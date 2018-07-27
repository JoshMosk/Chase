#pragma once
#include "ABDecision.h"
class IsTargetInRangeDecision : public ABDecision
{
public:
	IsTargetInRangeDecision(Agent* pTarget, float fSightDistance);
	~IsTargetInRangeDecision();

	void MakeDecision(float fDeltaTime, Agent* pAgent) override;

	Agent* m_pTarget;

	float m_fSightDistance;
};

