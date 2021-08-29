#include "Surface.h"
#include "ChiliWin.h"
#include <assert.h>
#include <fstream>


Surface::Surface(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);

	BITMAPFILEHEADER bmFileHeader;
	file.read( reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader) );
	
	BITMAPINFOHEADER bmInfoHeader;
	file.read( reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader) );

	assert( bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32);
	assert( bmInfoHeader.biCompression == BI_RGB || bmInfoHeader.biCompression == BI_BITFIELDS );

	bool is32bit = (bmInfoHeader.biBitCount == 32);

	width = bmInfoHeader.biWidth;
	
	// Change direction of looping through pixel data if height is negative.
	int yStart;
	int yEnd;
	int dy;
	if (bmInfoHeader.biHeight < 0)
	{
		height = -bmInfoHeader.biHeight;
		yStart = 0;
		yEnd = height;
		dy = 1;
	}
	else
	{
		height = bmInfoHeader.biHeight;
		yStart = height - 1;
		yEnd = -1;
		dy = -1;
	}

	pPixels = new Color[width * height];

	file.seekg( bmFileHeader.bfOffBits );
	const int padding = (4 - (width * 3) % 4) % 4;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	for (int by = yStart; by != yEnd; by += dy)
	{
		for (int bx = 0; bx < width; bx++)
		{
			b = file.get();
			g = file.get();
			r = file.get();
			if (is32bit)
			{
				a = file.get();
			}
			pPixels[by * width + bx] = Color( r, g, b );
		}
		if (!is32bit)
		{
			file.seekg( padding, std::ios::cur );
		}
	}
}

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixels( new Color[ width*height ] )
{
}

Surface::Surface(const Surface& rhs)
	:
	Surface( rhs.width, rhs.height )
{
	// Deep copy member variable
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = rhs.pPixels[i];
	}
}

Surface::~Surface()
{
	delete[] pPixels;
	pPixels = nullptr;
}

Surface& Surface::operator=(const Surface& rhs)
{
	width = rhs.width;
	height = rhs.height;

	delete[] pPixels;

	const int nPixels = width * height;
	pPixels = new Color[nPixels];

	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = rhs.pPixels[i];
	}
	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);

	// Setting a certain pixel to a color
	pPixels[y * width + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < width);
	assert(y >= 0);
	assert(y < height);

	return pPixels[y * width + x];
}

int Surface::GetHeight() const
{
	return height;
}

int Surface::GetWidth() const
{
	return width;
}

const RectI& Surface::GetRect()
{
	return RectI( 0, width, 0, height );
}
