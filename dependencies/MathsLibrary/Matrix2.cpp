#include "Matrix2.h"
#include <math.h>

Matrix2::Matrix2()
{
	m[0] = 1.0f;
	m[1] = 0.0f;

	m[2] = 0.0f;
	m[3] = 1.0f;
}

Matrix2::Matrix2(float m00, float m01, float m10, float m11)
{
	m[0] = m00;
	m[1] = m01;

	m[2] = m10;
	m[3] = m11;
}

Matrix2::~Matrix2()
{

}

Vector2 Matrix2::operator*(Vector2 rhs)
{
	Vector2 result;

	result.x = (m[0] * rhs.x) + (m[2] * rhs.y);
	result.y = (m[1] * rhs.x) + (m[3] * rhs.y);

	return result;
}

Matrix2 Matrix2::operator*(Matrix2 rhs)
{
	Matrix2 result;

	result.m[0] = (m[0] * rhs.m[0]) + (m[2] * rhs.m[1]);
	result.m[1] = (m[1] * rhs.m[0]) + (m[3] * rhs.m[1]);

	result.m[2] = (m[0] * rhs.m[2]) + (m[2] * rhs.m[3]);
	result.m[3] = (m[1] * rhs.m[2]) + (m[3] * rhs.m[3]);
	
	return result;
}

Vector2& Matrix2::operator[](int index)
{
	if (index % 2 == 0)
		return *((Vector2*)(&m[0]));
	else if (index % 2 == 1)
		return *((Vector2*)(&m[2]));
}

Matrix2::operator float*()
{
	return &m[0];
}

void Matrix2::setRotate(float fRadians)
{
	m[0] = cos(fRadians);
	m[1] = sin(fRadians);
	m[2] = -sin(fRadians);
	m[3] = cos(fRadians);
}

void Matrix2::setScale(float x, float y)
{
	m[0] = x;
	m[3] = y;
}

void Matrix2::setScale(Vector2 scale)
{
	m[0] = scale.x;
	m[3] = scale.y;
}
