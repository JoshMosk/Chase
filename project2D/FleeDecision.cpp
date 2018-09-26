#include "FleeDecision.h"
#include "FleeBehaviour.h"
#include "Agent.h"
#include "Grid.h"
#include <iostream>

FleeDecision::FleeDecision(Agent* pSelf, Agent* pTarget, Grid* pGrid) : BaseDecision(pSelf)
{
	m_pFlee = new FleeBehaviour(pSelf);
	m_pTarget = pTarget;
	m_pGrid = pGrid;
}

FleeDecision::~FleeDecision()
{
	delete m_pFlee;
}

BaseDecision* FleeDecision::MakeDecision(float fDeltaTime)
{
	m_v2Path = m_pGrid->GetPath(m_pSelf->GetPosition(), m_pTarget->GetPosition(), true);
	if (m_v2Path.size() > 0)
		m_v2TargetDirection = m_pFlee->Update(fDeltaTime, m_v2Path.front());
	return this;
}