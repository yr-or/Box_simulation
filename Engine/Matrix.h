#pragma once

class Matrix
{
private:
	enum class Type
	{
		Column,
		Square
	};
public:
	float x0y0;
	float x1y0;
	float x0y1;
	float x1y1;
	Type type;
public:
	Matrix( float x0y0, float x0y1 );
	Matrix( float x0y0, float x1y0, float x0y1, float x1y1 );
	static Matrix& GetRotationMatrix( float angle_deg );
	Matrix& operator*( Matrix& rhs );
};
