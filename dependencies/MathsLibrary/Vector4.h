#pragma once
struct Vector4
{
	Vector4();		//default constructor
	Vector4(float x, float y, float z, float w);		//constructor that takes in x, y, z and w coordinates
	~Vector4();		//default destructor

	float squaredMagnitude();		//quicker less accurate length of vector
	float magnitude();		//length of the vector
	void normalise();		//sets magnitude to one
	float dot(Vector4 rhs);		//used to find out the relative direction of one vector based on another vector 
	Vector4 cross(Vector4 rhs);
	Vector4 Clamp(Vector4 min, Vector4 max);		//does stuff with three vectors and collision

	Vector4 operator+(Vector4 rhs);		//allows for two vectors to be added together
	Vector4 operator-(Vector4 rhs);		//allows for the subtracton of one vector from another
	Vector4 operator*(float rhs);		//allows for a vector to be multiplied by a float
	Vector4 operator/(float rhs);		//allows for a vector to be divided by a float

	float& operator[](int index);		//allows for the x, y, z and w coordinates to be modified via the subscript operator
	explicit operator float*();		//allows for explicit casting for accessing the x, y, z and w coordinates


	float x;
	float y;
	float z;
	float w;
};

static Vector4 operator*(float lhs, Vector4 rhs)		//allows for a float and a vector to be multiplied
{
	Vector4 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;

	return result;
}