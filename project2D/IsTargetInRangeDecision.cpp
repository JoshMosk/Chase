#include "IsTargetInRangeDecision.h"

IsTargetInRangeDecision::IsTargetInRangeDecision(Agent* pTarget, float fSightDistance)
{
	m_pTarget = pTarget;
	m_fSightDistance = fSightDistance;
}

IsTargetInRangeDecision::~IsTargetInRangeDecision()
{
}

void IsTargetInRangeDecision::MakeDecision(float fDeltaTime, Agent* pAgent)
{
	//JM:STARTHERE, need to make decision using sightdistance and the agent position
}