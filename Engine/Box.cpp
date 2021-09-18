#include "Box.h"


Box::Box( int x, int y, int width, float angle_deg )
	:
	center_pos( x, y ),
	width( width ),
	angle_deg(angle_deg),
	topleft( -(width / 2), -(width / 2) ),
	topright( (width / 2), -(width / 2) ),
	botleft( -(width / 2), (width / 2) ),
	botright( (width / 2), (width / 2) )
{}

void Box::Draw( Graphics& gfx ) const
{
	gfx.DrawBox( center_pos, width, topleft, color, angle_deg );
}

Vec2 Box::GetScreenVec( Vec2 v )
{
	Vec2 newt = (v + center_pos);
	return newt;
}

Vec2 Box::GetBoxVec( Vec2 v )
{
	return v + center_pos;
}


void Box::DoCollisions()
{
	Vec2 topleft_screen = GetScreenVec( topleft.Rotate( angle_deg ) );
	if (!Graphics::IsWithinScreen( topleft_screen ))
	{
		vel.x = -vel.x;
		angle_vel = -angle_vel;
	}
	Vec2 topright_screen = GetScreenVec( topright.Rotate( angle_deg ) );
	if (!Graphics::IsWithinScreen( topright_screen ))
	{
		vel.x = -vel.x;
		angle_vel = -angle_vel;
	}
	Vec2 botleft_screen = GetScreenVec( botleft.Rotate( angle_deg ) );
	if (!Graphics::IsWithinScreen( botleft_screen ))
	{
		vel.x = -vel.x;
		angle_vel = -angle_vel;
	}
	Vec2 botright_screen = GetScreenVec( botright.Rotate( angle_deg ) );
	if (!Graphics::IsWithinScreen( botright_screen ))
	{
		vel.x = -vel.x;
		angle_vel = -angle_vel;
	}

}

void Box::Update()
{
	DoCollisions();

	if (angle_deg >= 360)
	{
		angle_deg = (360 - angle_deg) + angle_vel;
	}
	else {
		angle_deg += angle_vel;
	}

	center_pos += vel;
	
}


