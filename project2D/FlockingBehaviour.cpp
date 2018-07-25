#include "FlockingBehaviour.h"
#include "Agent.h"

#include "FlockingSeperation.h"
#include "FlockingAlignment.h"
#include "FlockingCohesion.h"

FlockingBehaviour::FlockingBehaviour(Agent* pSelf)
	: BaseSteeringBehaviour(pSelf)
{
	fFlockDistance = 300.0f;

	m_pSeperation = new FlockingSeperation(this);
	m_pAlignment = new FlockingAlignment(this, m_pSelf);
	m_pCohesion = new FlockingCohesion(this, m_pSelf);

	m_pSeperation->m_fWeighting = 0.05f;
	m_pAlignment->m_fWeighting = 2.0f;
	m_pCohesion->m_fWeighting = 2.0f;
}

FlockingBehaviour::~FlockingBehaviour()
{
}

Vector2 FlockingBehaviour::Update(float fDeltaTime)
{
	CalcFlock();
	Vector2 v2TotalVelocity;


	for (int i = 0; i < m_flock.size(); i++)
	{
		float fRemaining = m_pSelf->GetMaxSpeed() - v2TotalVelocity.magnitude();
		if (fRemaining <= 0.0f)		//check to see if there is any velocity left to spend
		{
			break;
		}

		if (m_flock[i].fMagnitude < fFlockDistance)		//if flock is within flocking distance
		{
			//do things
			Vector2 v2SepForce;
			Vector2 v2AliForce;
			Vector2 v2CohForce;

			v2SepForce = m_pSeperation->Update(fDeltaTime, m_pSelf->GetPosition()) * m_pSeperation->m_fWeighting;
			v2AliForce = m_pAlignment->Update(fDeltaTime, Vector2()) * m_pAlignment->m_fWeighting;
			v2CohForce = m_pCohesion->Update(fDeltaTime,Vector2()) * m_pCohesion->m_fWeighting;

			if (v2SepForce.magnitude() < fRemaining)		//calculate seperation force
			{
				v2TotalVelocity = v2TotalVelocity + v2SepForce;
			}
			else
			{
				v2SepForce.normalise();
				v2SepForce = v2SepForce * fRemaining;

				v2TotalVelocity = v2TotalVelocity + v2SepForce;
			}

			if (v2AliForce.magnitude() < fRemaining)		//calculate alignment force
			{
				v2TotalVelocity = v2TotalVelocity + v2AliForce;
			}
			else
			{
				v2AliForce.normalise();
				v2AliForce = v2AliForce * fRemaining;

				v2TotalVelocity = v2TotalVelocity + v2AliForce;
			}

			if (v2CohForce.magnitude() < fRemaining)		//calculate cohesion force
			{
				v2TotalVelocity = v2TotalVelocity + v2CohForce;
			}
			else
			{
				v2CohForce.normalise();
				v2CohForce = v2CohForce * fRemaining;

				v2TotalVelocity = v2TotalVelocity + v2CohForce;
			}
		}
	}
	return v2TotalVelocity;
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