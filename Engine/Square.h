#pragma once

#include "Graphics.h"
#include "Colors.h"
#include "Matrix.h"
#include "Vec2.h"

class Square
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
	Vec2 vel = { 0.0f, 0.0f };
	float angle_vel = 0.0f;			// change in degrees per frame
	float mass = 10.0f;
public:
	Square( int x, int y, int width, float angle_deg = 0.0f );
	void Draw( Graphics& gfx ) const;
	Vec2 GetScreenVec( Vec2 v);
	Vec2 GetSquareVec( Vec2 v);
	bool DoCollisions();
	void Update();
	void testRotation(const Vec2& force, const Vec2& radius);
	void testLinearMotion(const Vec2& force, const float time);
};

