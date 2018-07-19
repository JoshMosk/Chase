#pragma once
#include "BaseSteeringBehaviour.h"
class FlockingBehaviour;

class FlockingAlignment : public BaseSteeringBehaviour
{
public:
	FlockingAlignment();
	~FlockingAlignment();

	Vector2 Update(float fDeltaTime, FlockingBehaviour* pFlocking, Agent* pAgent);
};

