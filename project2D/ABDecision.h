#pragma once
#include "BaseDecision.h"
class ABDecision : public BaseDecision
{
public:
	ABDecision(Agent* pSelf);
	~ABDecision();

	BaseDecision* A;
	BaseDecision* B;

	bool m_bCondition;

	BaseDecision* MakeDecision(float fDeltaTime) override;		//makes decision based on condition,should be used to derive specific classes from
};

