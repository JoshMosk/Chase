#include "Matrix4.h"
#include <math.h>

Matrix4::Matrix4(Vector3 pos)
{
	m[0] = 1.0f;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = 0.0f;

	m[4] = 0.0f;
	m[5] = 1.0f;
	m[6] = 0.0f;
	m[7] = 0.0f;

	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = 1.0f;
	m[11] = 0.0f;

	m[12] = pos.x;
	m[13] = pos.y;
	m[14] = pos.z;
	m[15] = 1.0f;
}

Matrix4::Matrix4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
{
	m[0] = m00;
	m[1] = m01;
	m[2] = m02;
	m[3] = m03;

	m[4] = m10;
	m[5] = m11;
	m[6] = m12;
	m[7] = m13;

	m[8] = m20;
	m[9] = m21;
	m[10] = m22;
	m[11] = m23;

	m[12] = m30;
	m[13] = m31;
	m[14] = m32;
	m[15] = m33;
}

Matrix4::~Matrix4()
{

}

Vector4 Matrix4::operator*(Vector4 rhs)
{
	Vector4 result;

	result.x = (m[0] * rhs.x) + (m[4] * rhs.y) + (m[8] * rhs.z) + (m[12] * rhs.w);
	result.y = (m[1] * rhs.x) + (m[5] * rhs.y) + (m[9] * rhs.z) + (m[13] * rhs.w);
	result.z = (m[2] * rhs.x) + (m[6] * rhs.y) + (m[10] * rhs.z) + (m[14] * rhs.w);
	result.w = (m[3] * rhs.x) + (m[7] * rhs.y) + (m[11] * rhs.z) + (m[15] * rhs.w);

	return result;
}

Matrix4 Matrix4::operator*(Matrix4 rhs)
{
	Matrix4 result;

	result.m[0] = (m[0] * rhs.m[0]) + (m[4] * rhs.m[1]) + (m[8] * rhs.m[2]) + (m[12] * rhs.m[3]);
	result.m[1] = (m[1] * rhs.m[0]) + (m[5] * rhs.m[1]) + (m[9] * rhs.m[2]) + (m[13] * rhs.m[3]);
	result.m[2] = (m[2] * rhs.m[0]) + (m[6] * rhs.m[1]) + (m[10] * rhs.m[2]) + (m[14] * rhs.m[3]);
	result.m[3] = (m[3] * rhs.m[0]) + (m[7] * rhs.m[1]) + (m[11] * rhs.m[2]) + (m[15] * rhs.m[3]);

	result.m[4] = (m[1] * rhs.m[4]) + (m[4] * rhs.m[5]) + (m[8] * rhs.m[6]) + (m[12] * rhs.m[7]);
	result.m[5] = (m[2] * rhs.m[4]) + (m[5] * rhs.m[5]) + (m[9] * rhs.m[6]) + (m[13] * rhs.m[7]);
	result.m[6] = (m[2] * rhs.m[4]) + (m[6] * rhs.m[5]) + (m[10] * rhs.m[6]) + (m[14] * rhs.m[7]);
	result.m[7] = (m[3] * rhs.m[5]) + (m[7] * rhs.m[5]) + (m[11] * rhs.m[6]) + (m[15] * rhs.m[7]);

	result.m[8] = (m[0] * rhs.m[8]) + (m[4] * rhs.m[9]) + (m[8] * rhs.m[10]) + (m[12] * rhs.m[11]);
	result.m[9] = (m[1] * rhs.m[8]) + (m[5] * rhs.m[9]) + (m[9] * rhs.m[10]) + (m[13] * rhs.m[11]);
	result.m[10] = (m[2] * rhs.m[8]) + (m[6] * rhs.m[9]) + (m[10] * rhs.m[10]) + (m[14] * rhs.m[11]);
	result.m[11] = (m[3] * rhs.m[8]) + (m[7] * rhs.m[9]) + (m[11] * rhs.m[10]) + (m[15] * rhs.m[11]);

	result.m[12] = (m[0] * rhs.m[12]) + (m[4] * rhs.m[13]) + (m[8] * rhs.m[14]) + (m[12] * rhs.m[15]);
	result.m[13] = (m[1] * rhs.m[12]) + (m[5] * rhs.m[13]) + (m[9] * rhs.m[14]) + (m[13] * rhs.m[15]);
	result.m[14] = (m[2] * rhs.m[12]) + (m[6] * rhs.m[13]) + (m[10] * rhs.m[14]) + (m[14] * rhs.m[15]);
	result.m[15] = (m[3] * rhs.m[12]) + (m[7] * rhs.m[13]) + (m[11] * rhs.m[14]) + (m[15] * rhs.m[15]);

	return result;
}

Vector4& Matrix4::operator[](int index)
{
	if (index % 4 == 0)
		return *((Vector4*)(&m[0]));
	else if (index % 4 == 1)
		return *((Vector4*)(&m[4]));
	else if (index % 4 == 2)
		return *((Vector4*)(&m[8]));
	else if (index % 4 == 3)
		return *((Vector4*)(&m[12]));
}

Matrix4::operator float*()
{
	return &m[0];
}

void Matrix4::setRotateX(float fRadians)
{
	m[5] = cos(fRadians);
	m[6] = sin(fRadians);
	m[9] = -sin(fRadians);
	m[10] = cos(fRadians);
}

void Matrix4::setRotateY(float fRadians)
{
	m[0] = cos(fRadians);
	m[2] = -sin(fRadians);
	m[8] = sin(fRadians);
	m[10] = cos(fRadians);
}

void Matrix4::setRotateZ(float fRadians)
{
	m[0] = cos(fRadians);
	m[1] = sin(fRadians);
	m[4] = -sin(fRadians);
	m[5] = cos(fRadians);
}

Vector3 Matrix4::GetPosition()
{
	return Vector3(m[12], m[13], m[14]);
}

float Matrix4::GetX()
{
	return m[12];
}

float Matrix4::GetY()
{
	return m[13];
}

float Matrix4::GetZ()
{
	return m[14];
}

void Matrix4::setPosition(float x, float y, float z)
{
	m[12] = x;
	m[13] = y;
	m[14] = z;
}

void Matrix4::setPosition(Vector3 pos)
{
	m[12] = pos.x;
	m[13] = pos.y;
	m[14] = pos.z;
}

void Matrix4::setScale(float x, float y, float z)
{
	m[12] = x;
	m[13] = y;
	m[14] = z;
}

void Matrix4::setScale(Vector3 scale)
{
	m[12] = scale.x;
	m[13] = scale.y;
	m[14] = scale.z;
}