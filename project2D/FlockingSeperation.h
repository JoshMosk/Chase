#pragma once
#include "BaseSteeringBehaviour.h"
class FlockingBehaviour;

class FlockingSeperation : public BaseSteeringBehaviour
{
public:
	FlockingSeperation();
	~FlockingSeperation();

	Vector2 Update(float fDeltaTime, FlockingBehaviour* pFlocking, Agent* pAgent);
};

