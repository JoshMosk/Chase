#include "FlockingAlignment.h"
#include "FlockingBehaviour.h"
#include "Agent.h"

FlockingAlignment::FlockingAlignment()
{
}

FlockingAlignment::~FlockingAlignment()
{
}

Vector2 FlockingAlignment::Update(float fDeltaTime, FlockingBehaviour* pFlocking, Agent* pAgent)
{
	int nFlockSize = pFlocking->GetFlock().size();

	Vector2 v2SumForce = Vector2(0, 0);

	for (int i = 0; i < nFlockSize; i++)
	{
		v2SumForce = v2SumForce + pFlocking->GetFlock()[i].pAgent->GetVelocity();
	}

	Vector2 v2Average = v2SumForce * (1.0f / (float)nFlockSize);

	Vector2 result = v2Average - pAgent->GetVelocity();

	return result * m_fWeighting;
}