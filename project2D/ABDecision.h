#pragma once
#include "BaseDecision.h"
class ABDecision : public BaseDecision
{
public:
	ABDecision();
	~ABDecision();

	BaseDecision* A;
	BaseDecision* B;

	bool m_bCondition;

	void MakeDecision(float fDeltaTime, Agent* pAgent) override;		//makes decision based on condition,should be used to derive specific classes from
};

