#include "Font.h"
#include <assert.h>
#include "SpriteEffect.h"

Font::Font( const std::string& filename, Color chroma )
	:
	surface( filename ),
	glyphWidth( surface.GetWidth() / nColumns ),
	glyphHeight( surface.GetHeight() / nRows ),
	chroma( chroma )
{
	assert( glyphWidth * nColumns == surface.GetWidth() );
	assert( glyphHeight * nRows == surface.GetHeight() );
}

void Font::DrawText( const std::string& text, const Vei2& pos, Graphics& gfx ) const
{
	Vei2 curPos = pos;
	for (char c : text)
	{
		if (c != '\n')
		{
			if (c >= firstChar + 1 && c <= lastChar)
			{
				gfx.DrawSprite( curPos.x, curPos.y, GetGlyphRect( c ), surface, SpriteEffect::ColorFill{ chroma, Colors::White } );
			}
			curPos.x += glyphWidth;
		}
		else
		{
			curPos.y += glyphHeight;
			curPos.x = pos.x;
		}
	}
}

RectI Font::GetGlyphRect( char c ) const
{
	assert( c >= firstChar && c <= lastChar );

	const int glyphIndex = c - ' ';
	const int yGlyph = glyphIndex / nColumns;
	const int xGlyph = glyphIndex % nColumns;

	return RectI( { xGlyph * glyphWidth, yGlyph * glyphHeight }, glyphWidth, glyphHeight );
}