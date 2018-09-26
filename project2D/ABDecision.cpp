#include "ABDecision.h"

ABDecision::ABDecision(Agent* pSelf) : BaseDecision(pSelf)
{
	A = nullptr;
	B = nullptr;
}

ABDecision::~ABDecision()
{
}

BaseDecision* ABDecision::MakeDecision(float fDeltaTime)		//makes decision based on condition,should be used to derive specific classes from
{
	if (m_bCondition)
	{
		if (A != nullptr)
		{
			return A->MakeDecision(fDeltaTime);
		}
	}
	else
	{
		if (B != nullptr)
		{
			return B->MakeDecision(fDeltaTime);
		}
	}
}