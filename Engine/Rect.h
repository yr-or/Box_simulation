#pragma once

#include "Vec2.h"

template <typename T>
class Rect
{
public:
	Rect() = default;
	Rect( T left_in, T right_in, T top_in, T bottom_in )
		:
		left( left_in ),
		right( right_in ),
		top( top_in ),
		bottom( bottom_in )
	{}

	Rect( const _Vec2<T>& topLeft, const _Vec2<T>& bottomRight )
		:
		Rect( topLeft.x, bottomRight.x, topLeft.y, bottomRight.y )
	{}

	Rect( const _Vec2<T>& topLeft, T width, T height )
		:
		Rect( topLeft, topLeft + _Vec2<T>( width, height ) )
	{}

	bool IsOverlappingWith( const Rect& other ) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}

	bool IsContainedBy( const Rect& other ) const
	{
		return left >= other.left && right <= other.right &&
			top >= other.top && bottom <= other.bottom;
	}

	Rect FromCenter( const _Vec2<T>& center, T halfWidth, T halfHeight )
	{
		const _Vec2<T> half( halfWidth, halfHeight );
		return Rect( center - half, center + half );
	}

	Rect GetExpanded( T offset ) const
	{
		return Rect( left - offset, right + offset, top - offset, bottom + offset );
	}

	_Vec2<T> GetCenter() const
	{
		return _Vec2<T>( (left + right) / 2, (top + bottom) / 2 );
	}

	bool Contains( const _Vec2<T>& pos ) const
	{
		return (pos.x <= right && pos.x >= left && pos.y <= bottom && pos.y >= top);
	}

	T GetWidth() const
	{
		return right - left;
	}

	T GetHeight() const
	{
		return bottom - top;
	}

public:
	T left;
	T right;
	T top;
	T bottom;
};

typedef Rect<int> RectI;
typedef Rect<float> RectF;