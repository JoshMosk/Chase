#pragma once
#include "Vector2.h"
class Agent;

class BaseSteeringBehaviour
{
public:
	BaseSteeringBehaviour(Agent* pSelf = nullptr);		//set the agent which the steering behaviour is being applied to 
	virtual ~BaseSteeringBehaviour();

	virtual Vector2 Update(float fDeltaTime, Vector2 v2Target) = 0;		//v2Target is the target of the steering behaviour

	void SetSelf(Agent* pAgent);		//set the agent which the steering behaviour is applied to 

	float m_fWeighting;
protected:
	Agent* m_pSelf;		//pSelf is the agent which the steering behaviour is applied to
};

