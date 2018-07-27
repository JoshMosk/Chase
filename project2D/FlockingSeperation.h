#pragma once
#include "BaseSteeringBehaviour.h"
class FlockingBehaviour;

class FlockingSeperation : public BaseSteeringBehaviour
{
public:
	FlockingSeperation(FlockingBehaviour* pFlocking, Agent* pSelf);
	~FlockingSeperation();

	Vector2 Update(float fDeltaTime, Vector2 v2Target);

	FlockingBehaviour* m_pFlock;
};

