#include "FleeBehaviour.h"
#include "Agent.h"

FleeBehaviour::FleeBehaviour(Agent* pSelf) : BaseSteeringBehaviour(pSelf)
{
}

FleeBehaviour::~FleeBehaviour()
{
}

Vector2 FleeBehaviour::Update(float fDeltaTime, Vector2* v2Target)
{
	Vector2 v2Dir =  m_pSelf->GetPosition() - *v2Target;		//get direction of target to flee from
	v2Dir.normalise();		//normalise direction for consistent speed
	
	v2Dir = v2Dir * m_pSelf->GetMaxSpeed();		//scale the direction to max velocity
	
	Vector2 v2Force = v2Dir - m_pSelf->GetVelocity();		//minus current velocity from direction to get the  difference in force
	
	return v2Force;
}