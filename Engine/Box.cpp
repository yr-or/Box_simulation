#include "Box.h"


Box::Box( int x, int y, int width )
	:
	topleft( x, y ),
	topright( x + width, y ),
	botleft( x, y + width ),
	botright( x + width, y + width )
{}

Box::Box( int x, int y, Vec2 top )
	:
	topleft( x, y ),
	topright( topleft + top )
{
	Vec2 left = Vec2( top.y, -top.x );
	botleft = topleft + left;
	botright = botleft + top;
}

Box::Box( int x, int y, int width, float angle )
{
	auto pi = std::acos( -1 );
	float angle_rad = (angle / 180) * pi;
	Vec2 top = Vec2( (width * std::cos( angle_rad )), (width * std::sin( angle_rad )) );

	topleft = Vec2( x, y );
	topright = topleft + top;
	Vec2 left = Vec2( top.y, -top.x );
	botleft = topleft + left;
	botright = botleft + top;
}

void Box::Draw( Graphics& gfx )
{
	gfx.DrawBox( topleft, topright, botleft, botright, color );
}

void Box::Rotate( int angle )
{
	
}

Matrix Box::GetColumnVector( Vec2 v )
{
	return Matrix(v.x, v.y);
}
