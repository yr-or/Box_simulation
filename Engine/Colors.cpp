#include "Colors.h"

bool Color::operator==( const Color& c )
{
	return (dword == c.dword);
}

bool Color::operator!=( const Color& c )
{
	return !(*this == c);
}
