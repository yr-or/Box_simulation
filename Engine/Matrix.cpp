#include "Matrix.h"
#include <cmath>

Matrix::Matrix( float x0y0, float x0y1 )
	:
	x0y0( x0y0 ),
	x0y1( x0y1 ),
	type( Type::Column )
{}

Matrix::Matrix( float x0y0, float x1y0, float x0y1, float x1y1 )
	:
	x0y0( x0y0 ),
	x1y0( x1y0 ),
	x0y1( x0y1 ),
	x1y1( x1y1 ),
	type( Type::Square )
{}

Matrix::Matrix( int angle )
	:
	x0y0( std::cos( angle ) ),
	x1y0( -std::sin( angle ) ),
	x0y1( std::sin( angle ) ),
	x1y1( std::cos( angle ) ),
	type( Type::Square )
{}

Matrix& Matrix::operator*( Matrix& rhs )
{
	if (rhs.type == Type::Column && type == Type::Square)
	{
		return Matrix( (rhs.x0y0 * x0y0 + rhs.x0y0 * x0y1), (rhs.x0y1 * x1y0 + rhs.x0y1 * x1y1) );
	}
	else
	{
		return rhs * (*this);
	}
}