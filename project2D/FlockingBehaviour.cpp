#include "FlockingBehaviour.h"
#include "Agent.h"

#include "FlockingSeperation.h"
#include "FlockingAlignment.h"
#include "FlockingCohesion.h"
#include <iostream>

FlockingBehaviour::FlockingBehaviour(Agent* pSelf)
	: BaseSteeringBehaviour(pSelf)
{
	m_fFlockDistance = 200.0f;
	v2TotalVelocity = Vector2(0, 0);

	m_pSeperation = new FlockingSeperation(this, m_pSelf);
	m_pAlignment = new FlockingAlignment(this, m_pSelf);
	m_pCohesion = new FlockingCohesion(this, m_pSelf);

	m_pSeperation->m_fWeighting = 0.05;
	m_pAlignment->m_fWeighting = 0.01f;
	m_pCohesion->m_fWeighting = 0.1f;
}

FlockingBehaviour::~FlockingBehaviour()
{
}

Vector2 FlockingBehaviour::Update(float fDeltaTime, Vector2 v2Target)
{
	CalcFlock();



	for (int i = 0; i < m_flock.size(); i++)
	{

			float fDist = (m_pSelf->GetPosition() - m_flock[i].pAgent->GetPosition()).squaredMagnitude();		//distance of self to flocking agent
			float fDynamicSepForce = (m_fFlockDistance - fDist) * (1.0f / m_fFlockDistance);		//a force that changes the seperation force 
			float fDynamicCohForce = (fDist - m_fFlockDistance) * (1.0f / m_fFlockDistance);
			//JM:STARTHERE, need to get flocking working again due to speed bug,ugh
			//do things
			Vector2 v2SepForce;
			Vector2 v2AliForce;
			Vector2 v2CohForce;

			v2SepForce = m_pSeperation->Update(fDeltaTime, m_pSelf->GetPosition()) *m_pSeperation->m_fWeighting;
			v2AliForce = m_pAlignment->Update(fDeltaTime, Vector2()) *m_pAlignment->m_fWeighting;
			v2CohForce = m_pCohesion->Update(fDeltaTime, Vector2()) *m_pCohesion->m_fWeighting;

			v2TotalVelocity = v2TotalVelocity - (v2SepForce * fDynamicSepForce);		//calculate seperation force
								
			v2TotalVelocity = v2TotalVelocity + v2AliForce;		//calculate alignment force
						
			v2TotalVelocity = v2TotalVelocity + (v2CohForce * fDynamicCohForce); //* fDynamicForce);		//calculate cohesion force

	}
	//need to truncate if velocity mag is bigger than max speed 
	if (v2TotalVelocity.squaredMagnitude() > m_pSelf->GetMaxSpeed() * m_pSelf->GetMaxSpeed())
	{
		v2TotalVelocity.normalise();
		v2TotalVelocity = v2TotalVelocity * m_pSelf->GetMaxSpeed();

		//v2TotalVelocity = v2TotalVelocity + v2CohForce;
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