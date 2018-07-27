#include "FlockingCohesion.h"
#include "SeekBehaviour.h"
#include "FlockingBehaviour.h"
#include "Agent.h"

FlockingCohesion::FlockingCohesion(FlockingBehaviour* pFlocking, Agent* pSelf)
{
	m_pSeek = new SeekBehaviour(m_pSelf);
	m_pFlock = pFlocking;
	m_pSelf = pSelf;
}

FlockingCohesion::~FlockingCohesion()
{
	delete m_pSeek;
}

Vector2 FlockingCohesion::Update(float fDeltaTime, Vector2 v2Target)
{
	int nFlockSize = m_pFlock->GetFlock().size();

	Vector2 v2SumForce;

	v2SumForce = Vector2(0, 0);

	for (int i = 0; i < nFlockSize; i++)
	{
		if ((m_pSelf->GetPosition() - m_pFlock->m_flock[i].pAgent->GetPosition()).squaredMagnitude() < m_pFlock->m_fFlockDistance * m_pFlock->m_fFlockDistance)
		{
			v2SumForce = v2SumForce + m_pFlock->GetFlock()[i].pAgent->GetPosition();
		}
	}

	Vector2 v2Average = v2SumForce * (1.0f / (float)nFlockSize);

	m_pSeek->SetSelf(m_pSelf);
	Vector2 result = m_pSeek->Update(fDeltaTime, v2Average);

	return result * m_fWeighting;
}
