#pragma once
#include "Vector4.h"
#include "Vector3.h"

struct Matrix4
{
	Matrix4(Vector3 pos);
	Matrix4(float m00 = 1.0f, float m01 = 0.0f, float m02 = 0.0f, float m03 = 0.0f, float m10 = 0.0f, float m11 = 1.0f, float m12 = 0.0f, float m13 = 0.0f, float m20 = 0.0f, float m21 = 0.0f, float m22 = 1.0f, float m23 = 0.0f, float m30 = 0.0f, float m31 = 0.0f, float m32 = 0.0f, float m33 = 1.0f);
	~Matrix4();

	Vector4 operator*(Vector4 rhs);
	Matrix4 operator*(Matrix4 rhs);

	Vector4& operator[](int index);

	explicit operator float*();

	Vector3 GetPosition();
	float GetX();
	float GetY();
	float GetZ();

	void setRotateX(float fRadians);
	void setRotateY(float fRadians);
	void setRotateZ(float fRadians);

	void setPosition(float x, float y, float z);
	void setPosition(Vector3 pos);

	void setScale(float x, float y, float z);
	void setScale(Vector3 scale);

	float m[16];
};

