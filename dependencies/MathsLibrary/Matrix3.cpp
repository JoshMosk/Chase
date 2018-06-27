#include "Matrix3.h"
#include <math.h>

Matrix3::Matrix3(Vector2 pos)
{
	m[0] = 1.0f;
	m[1] = 0.0f;
	m[2] = 0.0f;

	m[3] = 0.0f;
	m[4] = 1.0f;
	m[5] = 0.0f;

	m[6] = pos.x;
	m[7] = pos.y;
	m[8] = 1.0f;
}

Matrix3::Matrix3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
{
	m[0] = m00;
	m[1] = m01;
	m[2] = m02;

	m[3] = m10;
	m[4] = m11;
	m[5] = m12;

	m[6] = m20;
	m[7] = m21;
	m[8] = m22;
}

Matrix3::~Matrix3()
{

}

Vector3 Matrix3::operator*(Vector3 rhs)
{
	Vector3 result;

	result.x = (m[0] * rhs.x) + (m[3] * rhs.y) + (m[6] * rhs.z);
	result.y = (m[1] * rhs.x) + (m[4] * rhs.y) + (m[7] * rhs.z);
	result.z = (m[2] * rhs.x) + (m[5] * rhs.y) + (m[8] * rhs.z);

	return result;
}

Matrix3 Matrix3::operator*(Matrix3 rhs)
{
	Matrix3 result;

	result.m[0] = (m[0] * rhs.m[0]) + (m[3] * rhs.m[1]) + (m[6] * rhs.m[2]);
	result.m[1] = (m[1] * rhs.m[0]) + (m[4] * rhs.m[1]) + (m[7] * rhs.m[2]);
	result.m[2] = (m[2] * rhs.m[0]) + (m[5] * rhs.m[1]) + (m[8] * rhs.m[2]);

	result.m[3] = (m[0] * rhs.m[3]) + (m[3] * rhs.m[4]) + (m[6] * rhs.m[5]);
	result.m[4] = (m[1] * rhs.m[3]) + (m[4] * rhs.m[4]) + (m[7] * rhs.m[5]);
	result.m[5] = (m[2] * rhs.m[3]) + (m[5] * rhs.m[4]) + (m[8] * rhs.m[5]);

	result.m[6] = (m[0] * rhs.m[6]) + (m[3] * rhs.m[7]) + (m[6] * rhs.m[8]);
	result.m[7] = (m[1] * rhs.m[6]) + (m[4] * rhs.m[7]) + (m[7] * rhs.m[8]);
	result.m[8] = (m[2] * rhs.m[6]) + (m[5] * rhs.m[7]) + (m[8] * rhs.m[8]);

	return result;
}

Vector3& Matrix3::operator[](int index)
{
	if (index % 3 == 0)
		return *((Vector3*)(&m[0]));
	else if (index % 3 == 1)
		return *((Vector3*)(&m[3]));
	else if (index % 3 == 2)
		return *((Vector3*)(&m[6]));
}

Matrix3::operator float*()
{
	return &m[0];
}

void Matrix3::setRotateX(float fRadians)
{
	m[4] = cos(fRadians);
	m[5] = sin(fRadians);
	m[7] = -sin(fRadians);
	m[8] = cos(fRadians);
}

void Matrix3::setRotateY(float fRadians)
{
	m[0] = cos(fRadians);
	m[2] = -sin(fRadians);
	m[6] = sin(fRadians);
	m[8] = cos(fRadians);
}

void Matrix3::setRotateZ(float fRadians)
{
	m[0] = cos(fRadians);
	m[1] = sin(fRadians);
	m[3] = -sin(fRadians);
	m[4] = cos(fRadians);
}

Vector2 Matrix3::GetPosition()
{
	return Vector2(m[6], m[7]);
}

float Matrix3::GetX()
{
	return m[6];
}

float Matrix3::GetY()
{
	return m[7];
}

void Matrix3::setPosition(float x, float y)
{
	m[6] = x;
	m[7] = y;
}

void Matrix3::setPosition(Vector2 pos)
{
	m[6] = pos.x;
	m[7] = pos.y;
}

void Matrix3::setScale(float x, float y)
{
	m[0] = x;
	m[4] = y;
}

void Matrix3::setScale(Vector2 scale)
{
	m[0] = scale.x;
	m[4] = scale.y;
}