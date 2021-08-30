#include "Font.h"

Font::Font( const std::string& str, Vei2 pos )
	:
	text(str),
	screenPos(pos)
{
	for (char c : text)
	{
		Vei2 dimensions = Vei2( 16, 28 );
		Vei2 topleft = Vei2( (c % 32) * 16, ((c / 32) - 1) * 28 );
		Vei2 botright = Vei2( topleft + dimensions );

		chars.emplace_back( topleft, botright );
	}
}

void Font::Update( Vei2 pos )
{
	screenPos = pos;
}

void Font::DrawText( Graphics& gfx )
{
	for (int i = 0; i < chars.size(); i++)
	{
		gfx.DrawSpriteColor( screenPos.x + (i * 16), screenPos.y, chars[i], glyphs, Colors::White, Colors::White );
	}
}
