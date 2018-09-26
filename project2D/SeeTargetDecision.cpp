#include "SeeTargetDecision.h"
#include "Agent.h"
#include <iostream>

SeeTargetDecision::SeeTargetDecision(Agent* pSelf, Agent* pTarget) : ABDecision(pSelf)
{
	m_pTarget = pTarget;
}

SeeTargetDecision::~SeeTargetDecision()
{
}

BaseDecision* SeeTargetDecision::MakeDecision(float fDeltaTime)
{
	if (m_pTarget ->GetPosition().dot(m_pSelf->GetPosition()) < m_fVisionAngle * m_fVisionAngle)
	{
		std::cout << m_pTarget->GetPosition().dot(m_pSelf->GetPosition()) << std::endl;
		m_bCondition = true;
		return ABDecision::MakeDecision(fDeltaTime);
	}
	else
	{
		m_bCondition = false; 
		return ABDecision::MakeDecision(fDeltaTime);
	}	
}
