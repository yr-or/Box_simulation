#include "Colors.h"

bool Color::operator==( const Color& c ) const
{
	return (dword == c.dword);
}

bool Color::operator!=( const Color& c ) const
{
	return !(*this == c);
}
