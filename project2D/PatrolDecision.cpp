#include "PatrolDecision.h"
#include "PatrolBehaviour.h"
#include "Grid.h"
#include "Agent.h"

PatrolDecision::PatrolDecision(Agent* pSelf, Grid* pGrid) : BaseDecision(pSelf)
{
	m_pPatrol = new PatrolBehaviour(pSelf);
	m_pGrid = pGrid;
}


PatrolDecision::~PatrolDecision()
{
	delete m_pPatrol;
}

BaseDecision* PatrolDecision::MakeDecision(float fDeltaTime)
{
	
	m_v2Path = m_pGrid->GetPath(m_pSelf->GetPosition(), m_pPatrol->Update(fDeltaTime), true);

	if (m_v2Path.size() > 0)
		m_v2TargetDirection = m_v2Path.front();

	return this;
}