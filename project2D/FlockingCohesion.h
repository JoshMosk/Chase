#pragma once
#include "BaseSteeringBehaviour.h"
class FlockingBehaviour;
class SeekBehaviour;

class FlockingCohesion : public BaseSteeringBehaviour
{
public:
	FlockingCohesion();
	~FlockingCohesion();

	Vector2 Update(float fDeltaTime, FlockingBehaviour* pFlocking, Agent* pAgent);

private:
	SeekBehaviour * m_pSeek;
};

