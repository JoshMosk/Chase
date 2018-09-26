#pragma once
#include "BaseDecision.h"
class PatrolBehaviour;
class Grid;

class PatrolDecision : public BaseDecision
{
public:
	PatrolDecision(Agent* pSelf, Grid* pGrid);
	~PatrolDecision();

	PatrolBehaviour* m_pPatrol;

	Grid* m_pGrid;
	std::vector<Vector2> m_v2Path;

	BaseDecision* MakeDecision(float fDeltaTime) override;
};

