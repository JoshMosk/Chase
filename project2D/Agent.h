#pragma once
#include "GameObject.h"

class Agent : public GameObject
{
public:
	Agent(Vector2 v2Transform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture);
	virtual ~Agent();

	virtual void Update(float fDeltaTime);
	virtual void Draw(aie::Renderer2D* pRenderer);


	//setters and getters
	void SetVelocity(Vector2 v2Velocity);
	Vector2 GetVelocity();

	float GetMaxSpeed();

	void SetTargetPos(Vector2 v2NewTargetPos);
	Vector2 GetTargetPos();

protected:
	Vector2 m_v2Velocity;
	float m_fSpeed;
	float m_fMaxSpeed;

	Vector2 m_v2TargetPos;
};

