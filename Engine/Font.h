#pragma once

#include "Surface.h"
#include "Vei2.h"
#include <vector>
#include "Graphics.h"

class Font
{
private:
	const Surface& glyphs = Surface("Fixedsys16x28.bmp");
	std::vector<RectI> chars;
	Vei2 screenPos;
	std::string text;
public:
	Font( const std::string& str, Vei2 pos );
	void Update( Vei2 pos );
	void DrawText( Graphics& gfx );
};

