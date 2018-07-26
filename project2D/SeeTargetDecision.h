#pragma once
#include "ABDecision.h"
#include "PiMaths.h"

#define NORMALVISION HALFPI/1.2f

class SeeTargetDecision : public ABDecision
{
public:
	SeeTargetDecision();
	~SeeTargetDecision();

	void MakeDecision(float fDeltaTime, Agent* pAgent) override;

	Agent* m_pTarget;
	float m_fVisionAngle = NORMALVISION;		//min 0, max pi, suggested using NORMALVISION aka halfpi/1.2f
};

