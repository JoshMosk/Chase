#pragma once
#include "BaseSteeringBehaviour.h"

class SeekBehaviour : public BaseSteeringBehaviour
{
public:
	SeekBehaviour(Agent* pSelf = nullptr);
	~SeekBehaviour();

	Vector2 Update(float fDeltaTime, Vector2 v2Target)override;		//pAgent is the agent which the steering behaviour is applied to

};

