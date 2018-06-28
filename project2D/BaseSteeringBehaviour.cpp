#include "BaseSteeringBehaviour.h"

BaseSteeringBehaviour::BaseSteeringBehaviour(Agent* pSelf)
{
	m_pSelf = pSelf;
}

BaseSteeringBehaviour::~BaseSteeringBehaviour()
{
}

void BaseSteeringBehaviour::SetSelf(Agent* pAgent)
{
	m_pSelf = pAgent;
}