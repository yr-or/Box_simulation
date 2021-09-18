#pragma once

#include "Graphics.h"
#include "Colors.h"
#include "Matrix.h"
#include "Vec2.h"

class Box
{
private:
	Color color = Colors::Green;
	Vec2 center;
	float width;
	float angle_deg;
	Vec2 topleft;
public:
	Box( int x, int y, int width, float angle_deg = 0.0f );
	void Draw( Graphics& gfx );
	void Rotate( float angle );
};

