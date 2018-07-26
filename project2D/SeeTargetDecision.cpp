#include "SeeTargetDecision.h"
#include "Agent.h"

SeeTargetDecision::SeeTargetDecision()
{
}

SeeTargetDecision::~SeeTargetDecision()
{
}

void SeeTargetDecision::MakeDecision(float fDeltaTime, Agent* pAgent)
{
	if (pAgent->GetPosition().dot(m_pTarget->GetPosition()) < m_fVisionAngle)
	{
		m_bCondition = true;
		ABDecision::MakeDecision(fDeltaTime, pAgent);
	}
	else
	{
		m_bCondition = false; 
		ABDecision::MakeDecision(fDeltaTime, pAgent);
	}	
}
