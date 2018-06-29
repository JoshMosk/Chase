#pragma once
#include "BaseSteeringBehaviour.h"

class WanderBehaviour : public BaseSteeringBehaviour
{
public:
	WanderBehaviour(Agent* pSelf, float fRadius, float fDistance, float fJitter);
	~WanderBehaviour();

	Vector2 Update(float fDeltaTime, Vector2* v2Target);		//v2Target is not used, just there to override BaseSteeringBehaviour Update

	float m_fRadius;
	float m_fDistance;
	float m_fJitter;
	Vector2 m_v2PrevTarget
};

