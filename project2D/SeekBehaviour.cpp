#include "SeekBehaviour.h"
#include "Agent.h"

SeekBehaviour::SeekBehaviour()
{
}

SeekBehaviour::~SeekBehaviour()
{
}

Vector2 SeekBehaviour::Update(float fDeltaTime, Vector2* v2Target)
{
	Vector2 v2Dir = *v2Target - m_pSelf->GetPosition();		//get direction of target
	v2Dir.normalise();		//normalise direction for consistent speed

	v2Dir = v2Dir * m_pSelf->GetMaxSpeed();		//scale the direction to max velocity

	Vector2 v2Force = v2Dir - m_pSelf->GetVelocity();		//minus current velocity from direction to get the  difference in force

	return v2Force;
}