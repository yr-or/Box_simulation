#pragma once

#include "Graphics.h"
#include "Colors.h"
#include "Matrix.h"
#include "Vec2.h"

class Box
{
private:
	Color color = Colors::Green;
	Vec2 center_pos;
	float width;
	float angle_deg;
	Vec2 topleft;
	Vec2 topright;
	Vec2 botleft;
	Vec2 botright;
	Vec2 vel = {3.0f, 0.0f};
	float angle_vel = 2.0f;
public:
	Box( int x, int y, int width, float angle_deg = 0.0f );
	void Draw( Graphics& gfx ) const;
	Vec2 GetScreenVec( Vec2 v);
	Vec2 GetBoxVec( Vec2 v);
	void DoCollisions();
	void Update();
};

