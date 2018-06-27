#include "PiMaths.h"

float DegToRad(float degrees)		//convert degrees to radians
{
return degrees * (PI / 180);
}

float RadToDeg(float radians)		//convert radians to degrees
{
	return radians * (180 / PI);
}