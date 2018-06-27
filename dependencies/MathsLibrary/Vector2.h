#pragma once

struct Vector2
{
	Vector2();		//default constructor
	Vector2(float x, float y);		//constructor that takes in x and y coordinates
	~Vector2();		//default destructor

	float squaredMagnitude();		//quicker less accurate length of vector
	float magnitude();		//length of the vector
	void normalise();		//sets magnitude to one
	float dot(Vector2 rhs);		//used to find out the relative direction of one vector based on another vector 
	Vector2 Clamp(Vector2 min, Vector2 max);		//does stuff with three vectors and collision

	Vector2 operator+(Vector2 rhs);		//allows for two vectors to be added together
	Vector2 operator-(Vector2 rhs);		//allows for the subtracton of one vector from another
	Vector2 operator*(float rhs);		//allows for a vector to be multiplied by a float
	Vector2 operator/(float rhs);		//allows for a vector to be divided by a float

	float& operator[](int index);		//allows for the x and y coordinates to be modified via the subscript operator
	explicit operator float*();		//allows for explicit casting for accessing the x and y coordinates


	float x;
	float y;
};

static Vector2 operator*(float lhs, Vector2 rhs)		//allows for a float and a vector to be multiplied
{
	Vector2 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}
