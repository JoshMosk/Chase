#pragma once
#include "GameObject.h"
#include <vector>

class Agent : public GameObject
{
public:
	Agent(Vector2 m3Tranform, float fRadiansRotation, float fMaxSpeed, aie::Texture* pTexture);
	virtual ~Agent();

	virtual void Update(float fDeltaTime);
	virtual void Draw(aie::Renderer2D* pRenderer);


	//setters and getters
	void SetVelocity(Vector2 v2Velocity);
	Vector2 GetVelocity();

	float GetMaxSpeed();

protected:
	Vector2 m_v2Velocity;
	float m_fMaxSpeed;
};

