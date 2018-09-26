#include "IsTargetInRangeDecision.h"
#include "Agent.h"
#include <iostream>

IsTargetInRangeDecision::IsTargetInRangeDecision(Agent* pSelf, Agent* pTarget, float fSightDistance) : ABDecision(pSelf)
{
	m_fSightDistance = fSightDistance;
	m_pTarget = pTarget;
}

IsTargetInRangeDecision::~IsTargetInRangeDecision()
{
}

BaseDecision* IsTargetInRangeDecision::MakeDecision(float fDeltaTime)
{
	//JM:STARTHERE, need to make decision using sightdistance and the agent position
	Vector2 collVec = m_pSelf->GetPosition() - m_pTarget->GetPosition();
	float dist = collVec.squaredMagnitude();

	if (m_fSightDistance * m_fSightDistance > dist)
	{
		std::cout << "true" << std::endl;
		m_bCondition = true;
		return ABDecision::MakeDecision(fDeltaTime);
	}
	else
	{
		std::cout << "false" << std::endl;
		m_bCondition = false;
		return ABDecision::MakeDecision(fDeltaTime);
	}
}