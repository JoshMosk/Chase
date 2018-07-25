#pragma once
#include "BaseSteeringBehaviour.h"
class FlockingBehaviour;

class FlockingSeperation : public BaseSteeringBehaviour
{
public:
	FlockingSeperation(FlockingBehaviour* pFlocking);
	~FlockingSeperation();

	Vector2 Update(float fDeltaTime, Vector2 v2Target);

	FlockingBehaviour* pFlock;
};

