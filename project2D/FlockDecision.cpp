#include "FlockDecision.h"
#include "FlockingBehaviour.h"
#include "Human.h"
#include <iostream>

FlockDecision::FlockDecision(Agent* pSelf, Human* pHuman) : BaseDecision(pSelf)
{
	m_pSelf = pSelf;
	m_pFlock = new FlockingBehaviour(pSelf);
	m_pFlock->AddToFlock(pHuman);
}

FlockDecision::~FlockDecision()
{
	delete m_pFlock;
}

BaseDecision* FlockDecision::MakeDecision(float fDeltaTime)
{
	m_v2TargetDirection = m_pFlock->Update(fDeltaTime);
	return this;
}
