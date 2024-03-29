#pragma once

#include "Graphics.h"
#include "Colors.h"
#include "Matrix.h"
#include "Vec2.h"
#include <vector>

class Square
{
private:
	Color color;
	Vec2 center_pos;
	int width;
	float angle_deg;

	Vec2 topleft;
	Vec2 topright;
	Vec2 botleft;
	Vec2 botright;
	Vec2 vel = { 0.0f, 0.0f };
	float angle_vel = 0.0f;			// change in degrees per frame
	float mass = 10.0f;
	float min_x;
	float max_x;
public:
	Square( int x, int y, int width, float angle_deg = 0.0f, Color color = Colors::Green );  // x and y point to centre of square
	void Draw( Graphics& gfx ) const;
	Vec2 SquareToScreen( Vec2 v);
	Vec2 ScreenToSquare( Vec2 v);
	bool DoCollisions();
	bool DoWallCollisions();
	bool DoBoxCollisions();
	void Update();
	void testRotation( const Vec2& force, const Vec2& point, const float time );
	void testLinearMotion(const Vec2& force, const float time);
	void applyForce( const Vec2& force, const Vec2& point_screen, const float time );
	void Reset();
};

