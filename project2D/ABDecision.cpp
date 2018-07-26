#include "ABDecision.h"

ABDecision::ABDecision()
{
	A = nullptr;
	B = nullptr;
}

ABDecision::~ABDecision()
{
}

void ABDecision::MakeDecision(float fDeltaTime, Agent* pAgent)
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