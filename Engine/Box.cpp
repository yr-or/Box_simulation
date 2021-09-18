#include "Box.h"


Box::Box( int x, int y, int width )
	:
	center( x, y ),
	width( width ),
	topleft( -(width / 2), -(width / 2) ),
	topright( (width / 2), -(width / 2) ),
	botleft( -(width / 2), (width / 2) ),
	botright( (width / 2), (width / 2) )
{}


Box::Box( int x, int y, int width, float angle_deg )
	:
	Box( x, y, width )
{
	Rotate( angle_deg );
}

void Box::Draw( Graphics& gfx )
{
	gfx.DrawBox( center, width, topleft, topright, botleft, botright, color );
}

void Box::Rotate( int angle_deg )
{
	topleft.Rotate( angle_deg );
	topright.Rotate( angle_deg );
	botleft.Rotate( angle_deg );
	botright.Rotate( angle_deg );
}

