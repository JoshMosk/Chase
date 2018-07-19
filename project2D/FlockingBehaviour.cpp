#include "FlockingBehaviour.h"
#include "Agent.h"

FlockingBehaviour::FlockingBehaviour(Agent* pSelf)
	: BaseSteeringBehaviour(pSelf)
{
	fFlockDistance = 300.0f;
}

FlockingBehaviour::~FlockingBehaviour()
{
}

Vector2 FlockingBehaviour::Update(float fDeltaTime)
{
	CalcFlock();

	for (int i = 0; i < m_flock.size(); i++)
	{
		if (m_flock[i].fMagnitude < fFlockDistance)
		{

		}
	}
}

void FlockingBehaviour::CalcFlock()
{
	for (int i = 0; i < m_flock.size(); i++)
	{
		m_flock[i].fMagnitude = m_flock[i].pAgent->GetPosition().magnitude();
	}
}

void FlockingBehaviour::AddToFlock(Agent* pAgent)
{
	Boid newBoid;
	newBoid.pAgent = pAgent;
	newBoid.fMagnitude = pAgent->GetPosition().magnitude();

	m_flock.push_back(newBoid);
}

std::vector<Boid> FlockingBehaviour::GetFlock()
{
	return m_flock;
}