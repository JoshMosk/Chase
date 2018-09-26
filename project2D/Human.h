#pragma once
#include "Agent.h"
#include <Renderer2D.h>
class PatrolBehaviour;
class HumanDecisionMaking;
class Grid;

class Human : public Agent
{
public:
	Human(Vector2 v2Tranform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture, Agent* pMouse, Grid* pGrid);
	~Human();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	HumanDecisionMaking* m_pDecisionTree;
};

