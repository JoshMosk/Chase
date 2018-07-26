#pragma once
class Agent;

class BaseDecision
{
public:
	BaseDecision();
	virtual ~BaseDecision() = 0;

	virtual void MakeDecision(float fDeltaTime, Agent* pAgent) = 0;
};

