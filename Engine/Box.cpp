#include "Box.h"


Box::Box( int x, int y, int width, float angle_deg )
	:
	center( x, y ),
	width( width ),
	angle_deg(angle_deg),
	topleft( -(width / 2), -(width / 2) )
{}

void Box::Draw( Graphics& gfx )
{
	gfx.DrawBox( center, width, topleft, color, angle_deg );
}

void Box::Rotate( float angle )
{
	angle_deg += angle;
}

