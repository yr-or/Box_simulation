#pragma once

#include "Graphics.h"
#include "Colors.h"
#include "Matrix.h"
#include "Vec2.h"

class Box
{
private:
	Color color = Colors::Green;
	Vec2 topleft;
	Vec2 topright;
	Vec2 botleft;
	Vec2 botright;
public:
	Box( int x, int y, int width );
	Box( int x, int y, Vec2 top );
	Box( int x, int y, int width, float angle );
	void Draw( Graphics& gfx );
	void Rotate( int angle );
	Matrix GetColumnVector( Vec2 v );
};

