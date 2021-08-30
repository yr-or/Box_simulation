#pragma once

#include "Surface.h"
#include "Graphics.h"
#include "Vei2.h"
#include <vector>

class Animation
{
private:
	Color chroma;
	const Surface& sprite;
	std::vector<RectI> frames;
	int curFrame = 0;
	float holdTime;
	float curFrameTime = 0.0f;
private:
	void AdvanceFrame();
public:
	Animation( int x, int y, int width, int height, int count, const Surface& sprite, float holdTime, Color chroma = Colors::Magenta );
	void Update( float dt );
	void Draw( const Vei2& pos, Graphics& gfx ) const;
	void Draw( const Vei2& pos, const RectI& clipreg, Graphics& gfx ) const;
};