#pragma once
#include "Agent.h"
class Human;
class Mouse;
class DogDecisionMaking;
class Grid;

class Dog : public Agent
{
public:
	Dog(Vector2 v2Transform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture, Human* pHuman, Mouse* pMouse, Grid* pGrid);
	~Dog();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer) override;

	Mouse* m_pMouse;

	DogDecisionMaking* m_pDecisionTree;
};

