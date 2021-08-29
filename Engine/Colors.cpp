#include "Colors.h"

bool Color::operator==( const Color& c )
{
	return (this->GetR() == c.GetR() && this->GetG() == c.GetG() && this->GetB() == c.GetB());
}

bool Color::operator!=( const Color& c )
{
	return !(*this == c);
}
