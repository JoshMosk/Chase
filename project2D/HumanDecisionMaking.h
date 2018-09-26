#pragma once
class Agent;
class SeeTargetDecision;
class PatrolDecision;
class FleeDecision;
class IsTargetInRangeDecision;
class Grid;
#include "Vector2.h"

class HumanDecisionMaking
{
public:
	HumanDecisionMaking(Agent* pSelf, Agent* pMouse, Grid* pGrid);
	~HumanDecisionMaking();

	//can see mouse
	//yes
		//flee
	//no
		//patrol

	//IsTargetInRangeDecision* m_pCanSeeMouse;
	IsTargetInRangeDecision* m_pCanSeeMouse;
	PatrolDecision* m_pPatrol;
	FleeDecision* m_pFleeMouse;

	Vector2 Update(float fDeltaTime);
};

