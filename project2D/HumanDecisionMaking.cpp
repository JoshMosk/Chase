#include "HumanDecisionMaking.h"
#include "SeeTargetDecision.h"
#include "PatrolDecision.h"
#include "PatrolBehaviour.h"
#include "FleeDecision.h"
#include "IsTargetInRangeDecision.h"

HumanDecisionMaking::HumanDecisionMaking(Agent* pSelf, Agent* pMouse, Grid* pGrid)
{
	m_pPatrol = new PatrolDecision(pSelf, pGrid);
	m_pFleeMouse = new FleeDecision(pSelf, pMouse, pGrid);
	m_pCanSeeMouse = new IsTargetInRangeDecision(pSelf, pMouse, 500);//SeeTargetDecision(pSelf, pMouse);

	m_pPatrol->m_pPatrol->AddPatrolPoint(Vector2(200, 600));
	m_pPatrol->m_pPatrol->AddPatrolPoint(Vector2(600, 600));
	m_pPatrol->m_pPatrol->AddPatrolPoint(Vector2(600, 200));
	m_pPatrol->m_pPatrol->AddPatrolPoint(Vector2(200, 200));

	m_pCanSeeMouse->A = m_pFleeMouse;
	m_pCanSeeMouse->B = m_pPatrol;
}


HumanDecisionMaking::~HumanDecisionMaking()
{
	delete m_pPatrol;
}

Vector2 HumanDecisionMaking::Update(float fDeltaTime)
{
	//can see mouse
	//yes
		//flee
	//no
		//patrol

	BaseDecision* test;
	test = m_pCanSeeMouse->MakeDecision(fDeltaTime);

	return test->m_v2TargetDirection;
}
