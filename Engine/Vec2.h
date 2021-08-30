#pragma once

#include "Vei2.h"

class Vec2
{
public:
	Vec2() = default;
	Vec2( float x_in,float y_in );
	Vec2 operator+( const Vec2& rhs ) const;
	Vec2& operator+=( const Vec2& rhs );
	Vec2 operator*( float rhs ) const;
	Vec2& operator*=( float rhs );
	Vec2 operator-( const Vec2& rhs ) const;
	Vec2& operator-=( const Vec2& rhs );
	float GetLength() const;
	float GetLengthSq() const;
	Vec2& Normalize();
	Vec2 GetNormalized() const;
	explicit operator Vei2() const;
public:
	float x;
	float y;
};

namespace Directions
{
	static const Vec2 RIGHT = { 1.0f, 0.0f };
	static const Vec2 LEFT = { -1.0f, 0.0f };
	static const Vec2 UP = { 0.0f, -1.0f };
	static const Vec2 DOWN = { 0.0f, 1.0f };
}