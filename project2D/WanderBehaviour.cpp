#include "WanderBehaviour.h"
#include "Agent.h"
#include "PiMaths.h"
#include <stdlib.h>		//used for random functions
#include <time.h>		//used to seed rendom functions

WanderBehaviour::WanderBehaviour(Agent* pSelf, float fRadius, float fDistance, float fJitter) : BaseSteeringBehaviour(pSelf)
{
	
	m_v2PrevTarget.x = rand() / PI;
	m_v2PrevTarget.y = rand() / PI;
}

WanderBehaviour::~WanderBehaviour()
{
}

Vector2 WanderBehaviour::Update(float fDeltaTime, Vector2* v2Target)
{
	float fNewDir = m_pSelf->GetRotation();		//get direction of wander
	//v2newDir.normalise();		//scale direction down to one
	//v2newDir = v2newDir * m_fDistance;		//scale up to m_fDistance

	//Vector2 v2NewTarget;
	//v2NewTarget.x = -sinf(rand() / PI) * m_fRadius;
	//v2NewTarget.y = cosf(rand() / PI) * m_fRadius;

	Vector2 v2Jitter(rand(), rand());		//jitter direction randomised
	v2Jitter.normalise();//scale direction down to one
	v2Jitter = v2Jitter * m_fJitter;		//scale up to m_fDistance

	m_v2PrevTarget = m_v2PrevTarget + v2Jitter;		//jittered direction
	m_v2PrevTarget.normalise();		//scale jittered direction down to one
	m_v2PrevTarget = m_v2PrevTarget * m_fRadius;		//scale up to m_fRadius

	Vector2 v2Offset;		//offsets the wander in front of the agent 
	v2Offset.x = -sin(fNewDir) * m_fDistance;
	v2Offset.y = cosf(fNewDir) * m_fDistance;

	m_v2PrevTarget = m_v2PrevTarget + v2Offset + m_pSelf->GetPosition();

	return m_v2PrevTarget;
}
