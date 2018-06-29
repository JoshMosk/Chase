#include "WanderBehaviour.h"
#include "Agent.h"
#include "PiMaths.h"
#include <stdlib.h>		//used for random functions
#include <time.h>		//used to seed rendom functions

WanderBehaviour::WanderBehaviour(Agent* pSelf) : BaseSteeringBehaviour(pSelf)
{
	
	m_v2PrevTarget.x = rand() / TWOPI;
	m_v2PrevTarget.y = rand() / TWOPI;
}

WanderBehaviour::~WanderBehaviour()
{
}

void WanderBehaviour::Update(float fDeltaTime, Vector2* v2Target)
{
	float fNewDir = m_pSelf->GetRotation();		//get direction of wander
	//v2newDir.normalise();		//scale direction down to one
	//v2newDir = v2newDir * m_fDistance;		//scale up to m_fDistance



}
