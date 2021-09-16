#include "Matrix.h"
#include <cmath>

Matrix::Matrix( float x0y0, float x0y1 )
	:
	x0y0( x0y0 ),
	x0y1( x0y1 ),
	x1y0(-1),
	x1y1(-1),
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

Matrix& Matrix::GetRotationMatrix( float angle_deg )
{
	auto pi = std::acos( -1 );
	float angle_rad = (angle_deg / 180) * pi;
	return Matrix( std::cos( angle_rad ), -std::sin( angle_rad ), std::sin( angle_rad ), std::cos( angle_rad ) );
}


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

