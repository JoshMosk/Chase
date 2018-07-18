#pragma once
#include "Agent.h"
#include <Renderer2D.h>
class PatrolBehaviour;

class Human : public Agent
{
public:
	Human(Vector2 v2Tranform, float fRadiansRotation, float fMaxSpeed, aie::Texture* pTexture);
	~Human();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	PatrolBehaviour* m_patrol;
};

