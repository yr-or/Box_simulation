#pragma once

#include "Colors.h"
#include "Graphics.h"

namespace SpriteEffect
{
	class Copy
	{
	public:
		void operator()( Color cSrc, int xDst, int yDst, Graphics& gfx )
		{
			gfx.PutPixel( xDst, yDst, cSrc );
		}
	};

	class Chroma
	{
	private:
		Color chroma;
	public:
		Chroma( Color c )
			: chroma( c )
		{}
		void operator()( Color cSrc, int xDst, int yDst, Graphics& gfx )
		{
			if (cSrc != chroma)
			{
				gfx.PutPixel( xDst, yDst, cSrc );
			}
		}
	};

	class ColorFill
	{
	private:
		Color chroma;
		Color fill;
	public:
		ColorFill( Color c, Color f )
			: 
			chroma(c),
			fill(f)
		{}
		void operator()( Color cSrc, int xDst, int yDst, Graphics& gfx )
		{
			if (cSrc != chroma)
			{
				gfx.PutPixel( xDst, yDst, fill );
			}
		}
	};

	class Ghost
	{
	private:
		Color chroma;
	public:
		Ghost(Color c)
			: chroma(c)
		{}
		void operator()( Color cSrc, int xDst, int yDst, Graphics& gfx )
		{
			if (cSrc != chroma)
			{
				// Mix the sprite and background pixels
				const Color spritePixel = cSrc;
				const Color bgPixel = gfx.GetPixel( xDst, yDst );
				const Color mixedColor = Color::MixColors( spritePixel, bgPixel );

				gfx.PutPixel( xDst, yDst, mixedColor );
			}
		}
	};
}