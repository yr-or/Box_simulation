#pragma once

class Matrix
{
private:
	enum class Type
	{
		Column,
		Square
	};
private:
	float x0y0;
	float x1y0;
	float x0y1;
	float x1y1;
	Type type;
public:
	Matrix( float x0y0, float x0y1 );
	Matrix( float x0y0, float x1y0, float x0y1, float x1y1 );
	Matrix( int angle );
	Matrix& operator*( Matrix& rhs );
};