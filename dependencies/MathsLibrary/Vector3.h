#pragma once
struct Vector3
{
	Vector3();		//default constructor
	Vector3(float x, float y, float z);		//constructor that takes in x, y and z coordinates
	~Vector3();		//default destructor

	float squaredMagnitude();		//quicker less accurate length of vector
	float magnitude();		//length of the vector
	void normalise();		//sets magnitude to one
	float dot(Vector3 rhs);		//used to find out the relative direction of one vector based on another vector 
	Vector3 cross(Vector3 rhs);
	Vector3 Clamp(Vector3 min, Vector3 max);		//does stuff with three vectors and collision

	Vector3 operator+(Vector3 rhs);		//allows for two vectors to be added together
	Vector3 operator-(Vector3 rhs);		//allows for the subtracton of one vector from another
	Vector3 operator*(float rhs);		//allows for a vector to be multiplied by a float
	Vector3 operator/(float rhs);		//allows for a vector to be divided by a float

	float& operator[](int index);		//allows for the x, y and z coordinates to be modified via the subscript operator
	explicit operator float*();		//allows for explicit casting for accessing the x, y and z coordinates


	float x;
	float y;
	float z;
};

static Vector3 operator*(float lhs, Vector3 rhs)		//allows for a float and a vector to be multiplied
{
	Vector3 result;

	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	return result;
}