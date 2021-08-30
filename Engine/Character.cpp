#include "Character.h"

Character::Character( const Vec2& pos )
	:
	sprite("link90x90.bmp"),
	pos(pos)
{
	for (int i = 0; i < (int)Sequence::StandingLeft; i++)
	{
		animations.emplace_back( 90, 90*i, 90, 90, 4, sprite, 0.2f );
	}
	for (int i = 0; i < 4; i++)
	{
		animations.emplace_back( 0, 90*i, 90, 90, 1, sprite, 0.2f );
	}
}

void Character::Update( float dt )
{
	pos += vel * dt;
	animations[(int)curSequence].Update( dt );
}

void Character::SetDirection( const Vec2& dir )
{
	if (dir.x > 0.0f)
	{
		curSequence = Sequence::WalkingRight;
	}
	else if (dir.x < 0.0f)
	{
		curSequence = Sequence::WalkingLeft;
	}
	else if (dir.y < 0.0f)
	{
		curSequence = Sequence::WalkingUp;
	}
	else if (dir.y > 0.0f)
	{
		curSequence = Sequence::WalkingDown;
	}
	else
	{
		if (vel.x > 0.0f)
		{
			curSequence = Sequence::StandingRight;
		}
		else if (vel.x < 0.0f)
		{
			curSequence = Sequence::StandingLeft;
		}
		else if (vel.y < 0.0f)
		{
			curSequence = Sequence::StandingUp;
		}
		else if (vel.y > 0.0f)
		{
			curSequence = Sequence::StandingDown;
		}
	}
	vel = dir * speed;
}

void Character::Draw( Graphics& gfx ) const
{
	animations[(int)curSequence].Draw( (Vei2)pos, gfx );
}
