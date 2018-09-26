#pragma once
class Agent;
#include "Vector2.h"
#include <vector>

class BaseDecision
{
public:
	BaseDecision(Agent* pSelf);
	virtual ~BaseDecision();

	virtual BaseDecision* MakeDecision(float fDeltaTime);

	Vector2 m_v2TargetDirection;

	Agent* m_pSelf;
};

