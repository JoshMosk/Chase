#pragma once
#include "Vector3.h"
#include "Vector2.h"

struct Matrix3
{
	Matrix3(Vector2 pos);
	Matrix3(float m00 = 1.0f, float m01 = 0.0f, float m02 = 0.0f, float m10 = 0.0f, float m11 = 1.0f, float m12 = 0.0f, float m20 = 0.0f, float m21 = 0.0f, float m22 = 1.0f);
	~Matrix3();

	Vector3 operator*(Vector3 rhs);
	Matrix3 operator*(Matrix3 rhs);

	Vector3& operator[](int index);

	explicit operator float*();

	void setRotateX(float fRadians);
	void setRotateY(float fRadians);
	void setRotateZ(float fRadians);

	Vector2 GetPosition();
	float GetX();
	float GetY();

	void setPosition(float x, float y);
	void setPosition(Vector2 pos);

	void setScale(float x, float y);
	void setScale(Vector2 scale);

	float m[9];
};

