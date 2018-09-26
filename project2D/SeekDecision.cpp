#include "SeekDecision.h"
#include "SeekBehaviour.h" 
#include "Agent.h"
#include "Grid.h"

SeekDecision::SeekDecision(Agent* pSelf, Agent* pTarget, Grid* pGrid) : BaseDecision(pSelf)
{
	m_pSeek = new SeekBehaviour(pSelf);
	m_pTarget = pTarget;
	m_pGrid = pGrid;
}


SeekDecision::~SeekDecision()
{
	delete m_pSeek;
}

BaseDecision* SeekDecision::MakeDecision(float fDeltaTime)
{
	m_v2Path = m_pGrid->GetPath(m_pSelf->GetPosition(), m_pTarget->GetPosition(), true);
	if (m_v2Path.size() > 0)
		m_v2TargetDirection = m_pSeek->Update(fDeltaTime, m_v2Path.front());
	return this;
}