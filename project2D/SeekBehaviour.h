#pragma once
#include "BaseSteeringBehaviour.h"

class SeekBehaviour : public BaseSteeringBehaviour
{
public:
	SeekBehaviour();
	~SeekBehaviour();

	Vector2 Update(float fDeltaTime, Vector2* v2Target);		//pAgent is the agent which the steering behaviour is applied to
};

