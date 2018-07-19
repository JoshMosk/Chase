#include "FlockingCohesion.h"
#include "SeekBehaviour.h"
#include "FlockingBehaviour.h"
#include "Agent.h"

FlockingCohesion::FlockingCohesion()
{

}

FlockingCohesion::~FlockingCohesion()
{
	delete m_pSeek;
}

Vector2 FlockingCohesion::Update(float fDeltaTime, FlockingBehaviour* pFlocking, Agent* pAgent)
{
	int nFlockSize = pFlocking->GetFlock().size();

	Vector2 v2SumForce;

	v2SumForce = Vector2(0, 0);

	for (int i = 0; i < nFlockSize; i++)
	{
		v2SumForce = v2SumForce + pFlocking->GetFlock()[i].pAgent->GetPosition();
	}

	Vector2 v2Average = v2SumForce * (1.0f / (float)nFlockSize);

	m_pSeek->SetSelf(pAgent);
	Vector2 result = m_pSeek->Update(fDeltaTime, v2Average);

	return result * m_fWeighting
}
