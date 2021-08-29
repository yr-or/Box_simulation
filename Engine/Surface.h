#pragma once

#include "Colors.h"
#include <string>
#include "RectI.h"

class Surface
{
private:
	Color* pPixels = nullptr;
	int width;
	int height;
public:
	Surface(const std::string& filename);
	Surface(int width, int height);
	Surface(const Surface& rhs);
	~Surface();
	Surface& operator=(const Surface& rhs);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetHeight() const;
	int GetWidth() const;
	const RectI& GetRect();
};