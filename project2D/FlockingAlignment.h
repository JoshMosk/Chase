#pragma once
#include "BaseSteeringBehaviour.h"
class FlockingBehaviour;

class FlockingAlignment : public BaseSteeringBehaviour
{
public:
	FlockingAlignment(FlockingBehaviour* pFlocking, Agent* pSelf);
	~FlockingAlignment();

	Vector2 Update(float fDeltaTime, Vector2 v2Target);		//v2Target is not used

	FlockingBehaviour* pFlock;
};

