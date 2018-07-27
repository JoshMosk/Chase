#pragma once
#include "Agent.h"
class Human;
class FlockingBehaviour;

class Dog : public Agent
{
public:
	Dog(Vector2 v2Transform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture, Human* pHuman, Agent* pMouse);
	~Dog();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer) override;

	FlockingBehaviour* m_pFlock;


};

