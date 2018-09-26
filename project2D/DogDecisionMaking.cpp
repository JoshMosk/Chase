#include "DogDecisionMaking.h"
#include "IsTargetInRangeDecision.h"
#include "SeeTargetDecision.h"
#include "SeekDecision.h"
#include "FlockDecision.h"
#include "Agent.h"
#include "Human.h"
#include "Vector2.h"
#include "Grid.h"

DogDecisionMaking::DogDecisionMaking(Agent* pSelf, Human* pHuman, Agent* pMouse, Grid* pGrid)
{
	m_pHumanInRange = new IsTargetInRangeDecision(pSelf, pHuman, 500);
	m_pCanSeeMouse = new IsTargetInRangeDecision(pSelf, pMouse, 400);
	m_pSeekHuman = new SeekDecision(pSelf, (Agent*)pHuman, pGrid);
	m_pSeekMouse = new SeekDecision(pSelf, pMouse, pGrid);
	//m_pFlockHuman = new FlockDecision(pSelf, pHuman);

	//give links for tree structure
	m_pHumanInRange->A = m_pCanSeeMouse;
	m_pHumanInRange->B = m_pSeekHuman;
	m_pCanSeeMouse->A = m_pSeekMouse;
	m_pCanSeeMouse->B = m_pSeekHuman;
}

DogDecisionMaking::~DogDecisionMaking()
{
	//delete m_pFlockHuman;
	delete m_pSeekMouse;
	delete m_pSeekHuman;
	delete m_pCanSeeMouse;
	delete m_pHumanInRange;
}

Vector2 DogDecisionMaking::Update(float fDeltaTime)
{
	//is human in range
	//yes
		//is mouse in sight
		//yes
			//chase mouse
		//no
			//flock with human
	//no
		//seek human
	
	m_newDir = m_pHumanInRange->MakeDecision(fDeltaTime);


	return m_newDir->m_v2TargetDirection;
}
