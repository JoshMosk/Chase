#include "ABDecision.h"

ABDecision::ABDecision()
{
	A = nullptr;
	B = nullptr;
}

ABDecision::~ABDecision()
{
}

void ABDecision::MakeDecision(float fDeltaTime, Agent* pAgent)		//makes decision based on condition,should be used to derive specific classes from
{
	if (m_bCondition)
	{
		A->MakeDecision(fDeltaTime, pAgent);
	}
	else
	{
		B->MakeDecision(fDeltaTime, pAgent);
	}
}