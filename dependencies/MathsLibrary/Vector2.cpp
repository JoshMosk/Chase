#include "Vector2.h"
#include <math.h>

Vector2::Vector2()		//default constructor
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)		//constructor that takes in x and y coordinates
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()		//default destructor
{
}

float Vector2::squaredMagnitude()		//quicker less accurate length of vector
{
	return (x * x) + (y * y);
}

float Vector2::magnitude()		//length of the vector
{
	return sqrtf((x * x) + (y * y));
}

void Vector2::normalise()		//sets magnitude to one
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
}

float Vector2::dot(Vector2 rhs)		//used to find out the relative direction of one vector based on another vector 
{
	return (x * rhs.x) + (y * rhs.y);
}

Vector2 Vector2::Clamp(Vector2 min, Vector2 max)		//does stuff with three vectors and collision
{
	Vector2 result;
	result.x = x;
	result.y = y;
	if (x < min.x)
	{
		result.x = min.x;
	}
	if (y < min.y)
	{
		result.y = min.y;
	}

	if (x > max.x)
	{
		result.x = max.x;
	}
	if (y > max.y)
	{
		result.y = max.y;
	}
	return result;
}

Vector2 Vector2::operator+(Vector2 rhs)		//allows for two vectors to be added together
{
	Vector2 result;

	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;

	return result;
}

Vector2 Vector2::operator-(Vector2 rhs)		//allows for the subtracton of one vector from another
{
	Vector2 result;

	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;

	return result;
}

Vector2 Vector2::operator*(float rhs)		//allows for a vector to be multiplied by a float
{
	Vector2 result;

	result.x = this->x * rhs;
	result.y = this->y * rhs;

	return result;
}

Vector2 Vector2::operator/(float rhs)
{
	Vector2 result;

	result.x = this->x / rhs;
	result.y = this->y / rhs;

	return result;
}

float& Vector2::operator[](int index)		//allows for the x and y coordinates to be modified via the subscript operator
{
	if (index % 2 == 0)
		return x;
	else if (index % 2 == 1)
		return y;
}

Vector2::operator float*()		//allows for explicit casting for accessing the x and y coordinates
{
	return &x;
}