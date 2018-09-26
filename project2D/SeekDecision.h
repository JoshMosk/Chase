#pragma once
#include "BaseDecision.h"
class SeekBehaviour;
class Grid;

class SeekDecision : public BaseDecision
{
public:
	SeekDecision(Agent* pSelf,Agent* pTarget, Grid* pGrid);
	~SeekDecision();

	SeekBehaviour* m_pSeek;

	Agent* m_pTarget;

	Grid* m_pGrid;
	std::vector<Vector2> m_v2Path;

	BaseDecision* MakeDecision(float fDeltaTime) override;
};

