#pragma once
#include "Vector2.h"

struct Matrix2
{
	Matrix2();
	Matrix2(float m00, float m01, float m10, float m11);
	~Matrix2();

	Vector2 operator*(Vector2 rhs);
	Matrix2 operator*(Matrix2 rhs);

	Vector2& operator[](int index);

	explicit operator float*();

	void setRotate(float fRadians);

	void setScale(float x, float y);
	void setScale(Vector2 scale);

	float m[4];
};