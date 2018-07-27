#pragma once
#include "BaseSteeringBehaviour.h"
class FlockingBehaviour;
class SeekBehaviour;

class FlockingCohesion : public BaseSteeringBehaviour
{
public:
	FlockingCohesion(FlockingBehaviour* pFlocking, Agent* pSelf);
	~FlockingCohesion();

	Vector2 Update(float fDeltaTime, Vector2 v2Target);		//v2Target is not used

	FlockingBehaviour* m_pFlock;
private:
	SeekBehaviour * m_pSeek;
};

