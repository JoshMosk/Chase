#include "FlockingAlignment.h"
#include "FlockingBehaviour.h"
#include "Agent.h"

FlockingAlignment::FlockingAlignment(FlockingBehaviour* pFlocking, Agent* pSelf)
{
	m_pFlock = pFlocking;
	m_pSelf = pSelf;
}

FlockingAlignment::~FlockingAlignment()
{
}

Vector2 FlockingAlignment::Update(float fDeltaTime, Vector2 v2Target)
{
	int nFlockSize = m_pFlock->GetFlock().size();

	Vector2 v2SumForce = Vector2(0, 0);

	for (int i = 0; i < nFlockSize; i++)
	{
		if ((m_pSelf->GetPosition() - m_pFlock->m_flock[i].pAgent->GetPosition()).squaredMagnitude() < m_pFlock->m_fFlockDistance * m_pFlock->m_fFlockDistance)
		{
			v2SumForce = v2SumForce + m_pFlock->GetFlock()[i].pAgent->GetVelocity();
		}
	}

	Vector2 v2Average = v2SumForce * (1.0f / (float)nFlockSize);

	Vector2 result = v2Average - m_pSelf->GetVelocity();

	return result * m_fWeighting;
}