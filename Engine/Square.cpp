#include "Square.h"
#include <math.h>

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

Vec2 Square::SquareToScreen( Vec2 v )
{
	return (v + center_pos);
}

Vec2 Square::ScreenToSquare( Vec2 v )
{
	return v - center_pos;
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
	Vec2 topleft_screen = SquareToScreen( topleft.Rotate( angle_deg ) );
	Vec2 topright_screen = SquareToScreen( topright.Rotate( angle_deg ) );
	Vec2 botleft_screen = SquareToScreen( botleft.Rotate( angle_deg ) );
	Vec2 botright_screen = SquareToScreen( botright.Rotate( angle_deg ) );
	Vec2 corners[] = { topleft_screen, topright_screen, botleft_screen, botright_screen };
	
	for (Vec2 corner : corners)
	{
		if (!collisionTop && Graphics::IsTouchingTop( corner ))
		{
			// Velocities become forces at moment of contact as instant deceleration for 1 frame
			Vec2 force = vel * mass;
			vel = { 0.0f, 0.0f };
			angle_vel = 0.0f;
			Vec2 bounceForce = Vec2( force.x, -force.y );
			applyForce( bounceForce, corner, 1 );
			collisionTop = true;
		}
		if (!collisionLeft && Graphics::IsTouchingLeft( corner ))
		{
			Vec2 force = vel * mass;
			vel = { 0.0f, 0.0f };
			angle_vel = 0.0f;
			Vec2 bounceForce = Vec2( -force.x, force.y );
			applyForce( bounceForce, corner, 1 );
			collisionLeft = true;
		}
		if (!collisionBot && Graphics::IsTouchingBot( corner ))
		{
			Vec2 force = vel * mass;
			vel = { 0.0f, 0.0f };
			angle_vel = 0.0f;
			Vec2 bounceForce = Vec2( force.x, -force.y );
			applyForce( bounceForce, corner, 1 );
			collisionBot = true;
		}
		if (!collisionRight && Graphics::IsTouchingRight( corner ))
		{
			Vec2 force = vel * mass;
			vel = { 0.0f, 0.0f };
			angle_vel = 0.0f;
			Vec2 bounceForce = Vec2( -force.x, force.y );
			applyForce( bounceForce, corner, 1 );
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


void Square::testLinearMotion( const Vec2& force, const float time )
{
	Vec2 accel = force / mass;
	vel = vel + accel * time;
}

void Square::applyForce( const Vec2& force, const Vec2& point_screen, const float time )
{
	// point = point on square that force is applied
	Vec2 point_square = ScreenToSquare( point_screen );

	// Calculate velocity
	Vec2 accel = force / mass;
	vel = vel + accel * time;

	// Calculate angular velocity
	auto Pi = std::acos( -1 );
	float Torque = point_square.CrossProd( force );
	// Actual moment of inertia of square = ((2 * width * width) / 12) * mass;
	float momentOfInertia = 200.0f;
	float angularAccel = Torque / momentOfInertia;
	float angular_vel = angle_vel*2*Pi + angularAccel * time;
	angle_vel = angular_vel / (2 * Pi);
}

void Square::Reset()
{
	center_pos = { 400.0f, 300.0f };
	vel = { 0.0f, 0.0f };
	angle_vel = 0.0f;
	angle_deg = 0.0f;
}




