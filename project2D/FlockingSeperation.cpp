#include "FlockingSeperation.h"
#include "FlockingBehaviour.h"
#include "Agent.h"

FlockingSeperation::FlockingSeperation(FlockingBehaviour* pFlocking)
{
	pFlock = pFlocking;
}

FlockingSeperation::~FlockingSeperation()
{
}

Vector2 FlockingSeperation::Update(float fDeltaTime, Vector2 v2Target)
{
	int nFlockSize = pFlock->GetFlock().size();
	//Vector2 v2AgentPos = pAgent->GetPosition();

	Vector2 v2SumForce = Vector2(0, 0);

	for (int i = 0; i < nFlockSize; i++)
	{
		Vector2 v2BoidPos = pFlock->GetFlock()[i].pAgent->GetPosition();

		v2SumForce = v2SumForce + (v2BoidPos - v2Target);//v2AgentPos);
	}

	Vector2 v2Average = v2SumForce * (1.0f / (float)nFlockSize);

	return v2Average * m_fWeighting;
}