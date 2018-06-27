#include "Vector4.h"
#include <math.h>

Vector4::Vector4()		//default constructor
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(float x, float y, float z, float w)		//constructor that takes in x, y, z and w coordinates
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::~Vector4()		//default destructor
{
}

float Vector4::squaredMagnitude()		//quicker less accurate length of vector
{
	return (x * x) + (y * y) + (z * z) + (w * w);
}

float Vector4::magnitude()		//length of the vector
{
	return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
}

void Vector4::normalise()		//sets magnitude to one
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;
}

float Vector4::dot(Vector4 rhs)		//used to find out the relative direction of one vector based on another vector 
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w);
}

Vector4 Vector4::cross(Vector4 rhs)
{
	Vector4 result;
	result.x = (this->y * rhs.z) - (this->z * rhs.y);
	result.y = (this->z * rhs.x) - (this->x * rhs.z);
	result.z = (this->x * rhs.y) - (this->y * rhs.x);
	result.w = 0;

	return result;
}

Vector4 Vector4::Clamp(Vector4 min, Vector4 max)		//does stuff with three vectors and collision
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = w;

	if (x < min.x)
	{
		result.x = min.x;
	}
	if (y < min.y)
	{
		result.y = min.y;
	}
	if (z < min.z)
	{
		result.z = min.z;
	}
	if (w < min.w)
	{
		result.w = min.w;
	}

	if (x > max.x)
	{
		result.x = max.x;
	}
	if (y > max.y)
	{
		result.y = max.y;
	}
	if (z > max.z)
	{
		result.z = max.z;
	}
	if (w > max.w)
	{
		result.w = max.w;
	}

	return result;
}

Vector4 Vector4::operator+(Vector4 rhs)		//allows for two vectors to be added together
{
	Vector4 result;

	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;
	result.w = this->w + rhs.w;

	return result;
}

Vector4 Vector4::operator-(Vector4 rhs)		//allows for the subtracton of one vector from another
{
	Vector4 result;

	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	result.z = this->z - rhs.z;
	result.w = this->w - rhs.w;

	return result;
}

Vector4 Vector4::operator*(float rhs)		//allows for a vector to be multiplied by a float
{
	Vector4 result;

	result.x = this->x * rhs;
	result.y = this->y * rhs;
	result.z = this->z * rhs;
	result.w = this->w * rhs;

	return result;
}

Vector4 Vector4::operator/(float rhs)		//allows for a vector to be divided by a float
{
	Vector4 result;

	result.x = this->x / rhs;
	result.y = this->y / rhs;
	result.z = this->z / rhs;
	result.w = this->w / rhs;

	return result;
}

float& Vector4::operator[](int index)		//allows for the x, y, z and w coordinates to be modified via the subscript operator
{
	if (index % 4 == 0)
		return x;
	else if (index % 4 == 1)
		return y;
	else if (index % 4 == 2)
		return z;
	else if (index % 4 == 3)
		return w;
}

Vector4::operator float*()		//allows for explicit casting for accessing the x, y, z and w coordinates
{
	return &x;
}

