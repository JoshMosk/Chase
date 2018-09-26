#pragma once
#include "ABDecision.h"
class IsTargetInRangeDecision : public ABDecision
{
public:
	IsTargetInRangeDecision(Agent* pSelf, Agent* pTarget, float fSightDistance);
	~IsTargetInRangeDecision();

	BaseDecision* MakeDecision(float fDeltaTime) override;

	Agent* m_pTarget;

	float m_fSightDistance;
};

