#pragma once
#include "Animation.h"
#include "Vec2.h"

class Character
{
private:
	enum class Sequence
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};
private:
	Vec2 pos;
	Vec2 vel = { 0.0f, 0.0f };
	float speed = 100.0f;
	Surface sprite;
	std::vector<Animation> animations;
	Sequence curSequence = Sequence::StandingDown;
public:
	Character( const Vec2& pos );
	void Update( float dt );
	void SetDirection( const Vec2& dir );
	void Draw( Graphics& gfx ) const;
};



