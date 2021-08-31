#pragma once

#include "Surface.h"
#include "Vec2.h"
#include "Graphics.h"

class Font
{
private:
	Surface surface;
	int glyphWidth;
	int glyphHeight;
	static constexpr int nColumns = 32;
	static constexpr int nRows = 3;
	Color chroma;
	static constexpr int firstChar = ' ';
	static constexpr int lastChar = '~';
private:
	RectI GetGlyphRect( char c ) const;
public:
	Font( const std::string& filename, Color chroma = Colors::White );
	void DrawText( const std::string& text, const Vei2& pos, Graphics& gfx ) const;
};

