#pragma once

#include <cmath>

template <typename T>
class _Vec2
{
public:
	_Vec2() = default;
	_Vec2( T x_in, T y_in )
		:
		x( x_in ),
		y( y_in )
	{}

	template <typename S>
	explicit _Vec2( const _Vec2<S>& src)
		:
		x( (T)src.x ),
		y( (T)src.y )
	{}

	_Vec2 operator+( const _Vec2& rhs ) const
	{
		return _Vec2( x + rhs.x, y + rhs.y );
	}

	_Vec2& operator+=( const _Vec2& rhs )
	{
		return *this = *this + rhs;
	}

	_Vec2 operator*( T rhs ) const
	{
		return _Vec2( x * rhs, y * rhs );
	}

	_Vec2& operator*=( T rhs )
	{
		return *this = *this * rhs;
	}

	_Vec2 operator/( T rhs ) const
	{
		return _Vec2( x / rhs, y / rhs );
	}

	_Vec2 operator-( const _Vec2& rhs ) const
	{
		return _Vec2( x - rhs.x, y - rhs.y );
	}

	_Vec2& operator-=( const _Vec2& rhs )
	{
		return *this = *this - rhs;
	}
	bool operator==( const _Vec2& rhs ) const
	{
		return (x == rhs.x && y == rhs.y);
	}
	bool operator!=( const _Vec2& rhs ) const
	{
		return !(*this == rhs);
	}
	_Vec2 operator-()
	{
		return Vec2( -x, -y );
	}

	T GetLength() const
	{
		return (T)std::sqrt( GetLengthSq() );
	}

	T GetLengthSq() const
	{
		return x * x + y * y;
	}

	_Vec2& Normalize()
	{
		return *this = GetNormalized();
	}

	_Vec2 GetNormalized() const
	{
		const T len = GetLength();
		if (len != (T)0)
		{
			return *this * ((T)1 / len);
		}
		return *this;
	}
	_Vec2 GetUnitVector() const
	{
		return GetNormalized();
	}

	_Vec2 Rotate( float angle_deg ) const
	{
		auto pi = std::acos( -1 );
		float angle_rad = (angle_deg / 180) * pi;
		T x_tmp = x * (std::cos( angle_rad )) - y * (std::sin( angle_rad ));
		T y_tmp = x * (std::sin( angle_rad )) + y * (std::cos( angle_rad ));
		return { x_tmp, y_tmp };
	}

	float CrossProd( const _Vec2& rhs ) const
	{
		return x * rhs.y - y * rhs.x;
	}

public:
	T x;
	T y;
};

typedef _Vec2<float> Vec2;
typedef _Vec2<int> Vei2;

namespace Directions
{
	static const Vec2 RIGHT = { 1.0f, 0.0f };
	static const Vec2 LEFT = { -1.0f, 0.0f };
	static const Vec2 UP = { 0.0f, -1.0f };
	static const Vec2 DOWN = { 0.0f, 1.0f };
}