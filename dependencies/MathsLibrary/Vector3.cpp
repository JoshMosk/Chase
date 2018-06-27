#include "Vector3.h"
#include <math.h>

Vector3::Vector3()		//default constructor
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)		//constructor that takes in x, y and z coordinates
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()		//default destructor
{
}

float Vector3::squaredMagnitude()		//quicker less accurate length of vector
{
	return (x * x) + (y * y) + (z * z);
}

float Vector3::magnitude()		//length of the vector
{
	return sqrtf((x * x) + (y * y) + (z * z));
}

void Vector3::normalise()		//sets magnitude to one
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

float Vector3::dot(Vector3 rhs)		//used to find out the relative direction of one vector based on another vector 
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
}

Vector3 Vector3::cross(Vector3 rhs)
{
	Vector3 result;

	result.x = (this->y * rhs.z) - (this->z * rhs.y);
	result.y = (this->z * rhs.x) - (this->x * rhs.z);
	result.z = (this->x * rhs.y) - (this->y * rhs.x);

	return result;
}

Vector3 Vector3::Clamp(Vector3 min, Vector3 max)		//does stuff with three vectors and collision
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = z;

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
	return result;
}

Vector3 Vector3::operator+(Vector3 rhs)		//allows for two vectors to be added together
{
	Vector3 result;

	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;

	return result;
}

Vector3 Vector3::operator-(Vector3 rhs)		//allows for the subtracton of one vector from another
{
	Vector3 result;

	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	result.z = this->z - rhs.z;

	return result;
}

Vector3 Vector3::operator*(float rhs)		//allows for a vector to be multiplied by a float
{
	Vector3 result;

	result.x = this->x * rhs;
	result.y = this->y * rhs;
	result.z = this->z * rhs;

	return result;
}

Vector3 Vector3::operator/(float rhs)		//allows for a vector to be divided by a float
{
	Vector3 result;

	result.x = this->x / rhs;
	result.y = this->y / rhs;
	result.z = this->z / rhs;

	return result;
}

float& Vector3::operator[](int index)		//allows for the x, y and z coordinates to be modified via the subscript operator
{
	if (index % 3 == 0)
		return x;
	else if (index % 3 == 1)
		return y;
	else if (index % 3 == 2)
		return z;
}

Vector3::operator float*()		//allows for explicit casting for accessing the x, y and z coordinates
{
	return &x;
}

