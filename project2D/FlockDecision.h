#pragma once
#include "BaseDecision.h"
class FlockingBehaviour;
class Human;

class FlockDecision : public BaseDecision
{
public:
	FlockDecision(Agent* pSelf, Human* pHuman);
	~FlockDecision();

	Agent* m_pSelf;

	FlockingBehaviour* m_pFlock;

	BaseDecision* MakeDecision(float fDeltaTime) override;
};

