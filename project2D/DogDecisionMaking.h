#pragma once
class SeeTargetDecision;
class IsTargetInRangeDecision;
class SeekDecision;
class FlockDecision;
class Agent;
class Human;
class Grid;
#include "BaseDecision.h"
#include "Vector2.h"

class DogDecisionMaking
{
public:
	DogDecisionMaking(Agent* pSelf, Human* pHuman, Agent* pMouse, Grid* pGrid);
	~DogDecisionMaking();

	//is human in range
	//yes
		//is mouse in sight
		//yes
			//chase mouse
		//no
			//flock with human
	//no
		//seek human
	

	IsTargetInRangeDecision* m_pHumanInRange;
	IsTargetInRangeDecision* m_pCanSeeMouse;
	SeekDecision* m_pSeekHuman;
	SeekDecision* m_pSeekMouse;
	//FlockDecision* m_pFlockHuman;

	BaseDecision* m_newDir;

	Vector2 Update(float fDeltaTime);
};

