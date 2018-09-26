#pragma once
#include "BaseDecision.h"
class FleeBehaviour;
class Grid;

class FleeDecision : public BaseDecision
{
public:
	FleeDecision(Agent* pSelf, Agent* pTarget, Grid* pGrid);
	~FleeDecision();

	Agent* m_pTarget;
	FleeBehaviour* m_pFlee;
	Grid* m_pGrid;
	std::vector<Vector2> m_v2Path;

	BaseDecision* MakeDecision(float fDeltaTime) override;
};

