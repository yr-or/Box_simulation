#include "Animation.h"
#include "SpriteEffect.h"

Animation::Animation( int x, int y, int width, int height, int count, const Surface& sprite, float holdTime, Color chroma )
	:
	sprite(sprite),
	holdTime(holdTime),
	chroma(chroma)
{
	for (int i = 0; i < count; i++)
	{
		frames.emplace_back( x + (width * i), x + (width * (i+1)), y, (y + height) );
	}
}

void Animation::Update( float dt )
{
	curFrameTime += dt;
	while (curFrameTime >= holdTime)
	{
		AdvanceFrame();
		curFrameTime -= holdTime;
	}
}

void Animation::AdvanceFrame()
{
	if (++curFrame >= frames.size())
	{
		curFrame = 0;
	}
}


void Animation::Draw( const Vei2& pos, Graphics& gfx ) const
{
	gfx.DrawSprite( pos.x, pos.y, frames[curFrame], sprite, SpriteEffect::Chroma{chroma} );
}

void Animation::Draw( const Vei2& pos, const RectI& clipreg, Graphics& gfx ) const
{
	gfx.DrawSprite( pos.x, pos.y, frames[curFrame], clipreg, sprite, SpriteEffect::Chroma{ chroma } );
}
