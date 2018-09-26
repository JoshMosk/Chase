#include "BaseDecision.h"

BaseDecision::BaseDecision(Agent* pSelf)
{
	m_pSelf = pSelf;
}

BaseDecision::~BaseDecision()
{
}


BaseDecision* BaseDecision::MakeDecision(float fDeltaTime)
{
	return this;
}