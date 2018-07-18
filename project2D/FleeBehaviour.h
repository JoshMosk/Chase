#pragma once
#include "BaseSteeringBehaviour.h"

class FleeBehaviour : public BaseSteeringBehaviour
{
public:
	FleeBehaviour(Agent* pSelf = nullptr);
	~FleeBehaviour();

	virtual Vector2 Update(float fDeltaTime, Vector2 v2Target)override;
};

