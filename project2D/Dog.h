#pragma once
#include "Agent.h"
class Human;

class Dog : public Agent
{
public:
	Dog(Vector2 v2Transform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture, Human* pHuman);
	~Dog();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);
	
	Human* m_pHuman;
};
