#include "Square.h"


Square::Square( int x, int y, int width, float angle_deg )
	:
	center_pos( x, y ),
	width( width ),
	angle_deg(angle_deg),
	topleft( -(width / 2), -(width / 2) ),
	topright( (width / 2), -(width / 2) ),
	botleft( -(width / 2), (width / 2) ),
	botright( (width / 2), (width / 2) )
{}

void Square::Draw( Graphics& gfx ) const
{
	gfx.DrawSquare( center_pos, width, topleft, color, angle_deg );
}

Vec2 Square::GetScreenVec( Vec2 v )
{
	Vec2 newt = (v + center_pos);
	return newt;
}

Vec2 Square::GetSquareVec( Vec2 v )
{
	return v + center_pos;
}


bool Square::DoCollisions()
{
	/*
		If Square is touching wall
		Change direction
	*/

	bool collisionTop = false;
	bool collisionLeft = false;
	bool collisionBot = false;
	bool collisionRight = false;
	Vec2 topleft_screen = GetScreenVec( topleft.Rotate( angle_deg ) );
	Vec2 topright_screen = GetScreenVec( topright.Rotate( angle_deg ) );
	Vec2 botleft_screen = GetScreenVec( botleft.Rotate( angle_deg ) );
	Vec2 botright_screen = GetScreenVec( botright.Rotate( angle_deg ) );
	Vec2 corners[] = { topleft_screen, topright_screen, botleft_screen, botright_screen };
	
	for (Vec2 corner : corners)
	{
		if (!collisionTop && Graphics::IsTouchingTop(corner))
		{
			vel.y = -vel.y;
			angle_vel = -angle_vel;
			collisionTop = true;
		}
		if (!collisionLeft && Graphics::IsTouchingLeft( corner ))
		{
			vel.x = -vel.x;
			angle_vel = -angle_vel;
			collisionLeft = true;
		}
		if (!collisionBot && Graphics::IsTouchingBot( corner ))
		{
			vel.y = -vel.y;
			angle_vel = -angle_vel;
			collisionBot = true;
		}
		if (!collisionRight && Graphics::IsTouchingRight( corner ))
		{
			vel.x = -vel.x;
			angle_vel = -angle_vel;
			collisionRight = true;
		}
	}
	return collisionTop || collisionLeft || collisionBot || collisionRight;
}

void Square::Update()
{
	center_pos += vel;
	if (DoCollisions())
	{
		center_pos += vel;
	}

	if (angle_deg >= 360)
	{
		angle_deg = (angle_deg - 360) + angle_vel;
	}
	else {
		angle_deg += angle_vel;
	}
}

void Square::testRotation( const Vec2& force, const Vec2& radius )
{

}

void Square::testLinearMotion( const Vec2& force, const float time )
{
	Vec2 accel = force / mass;
	vel = vel + accel * time;
}




