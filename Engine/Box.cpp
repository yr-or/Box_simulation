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


bool Box::DoCollisions()
{
	/*
		If box is touching wall
		Change direction
	*/


	Vec2 topleft_screen = GetScreenVec( topleft.Rotate( angle_deg ) );
	Vec2 topright_screen = GetScreenVec( topright.Rotate( angle_deg ) );
	Vec2 botleft_screen = GetScreenVec( botleft.Rotate( angle_deg ) );
	Vec2 botright_screen = GetScreenVec( botright.Rotate( angle_deg ) );
	if (Graphics::IsOutsideScreen( topleft_screen ))
	{
		vel.x = -vel.x;
		angle_vel = -angle_vel;
		return true;
	}
	else if (Graphics::IsOutsideScreen( topright_screen ))
	{
		vel.x = -vel.x;
		angle_vel = -angle_vel;
		return true;
	}
	else if (Graphics::IsOutsideScreen( botleft_screen ))
	{
		vel.x = -vel.x;
		angle_vel = -angle_vel;
		return true;
	}
	else if (Graphics::IsOutsideScreen( botright_screen ))
	{
		vel.x = -vel.x;
		angle_vel = -angle_vel;
		return true;
	}

}

void Box::Update()
{
	center_pos += vel;
	if (DoCollisions())
	{
		center_pos += vel;
	}

	if (angle_deg >= 360)
	{
		angle_deg = (360 - angle_deg) + angle_vel;
	}
	else {
		angle_deg += angle_vel;
	}
}


