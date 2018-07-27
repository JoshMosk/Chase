#include "FlockingSeperation.h"
#include "FlockingBehaviour.h"
#include "Agent.h"

FlockingSeperation::FlockingSeperation(FlockingBehaviour* pFlocking, Agent* pSelf)
{
	m_pFlock = pFlocking;
	m_pSelf = pSelf;
}

FlockingSeperation::~FlockingSeperation()
{
}

Vector2 FlockingSeperation::Update(float fDeltaTime, Vector2 v2Target)
{
	int nFlockSize = m_pFlock->GetFlock().size();

	Vector2 v2SumForce = Vector2(0, 0);

	for (int i = 0; i < nFlockSize; i++)
	{
		if ((m_pSelf->GetPosition() - m_pFlock->m_flock[i].pAgent->GetPosition()).squaredMagnitude() < m_pFlock->m_fFlockDistance * m_pFlock->m_fFlockDistance)
		{
			Vector2 v2BoidPos = m_pFlock->GetFlock()[i].pAgent->GetPosition();

			v2SumForce = v2SumForce - (v2BoidPos - v2Target);
		}
	}

	Vector2 v2Average = v2SumForce * (1.0f / (float)nFlockSize);

	return v2Average * m_fWeighting;
}