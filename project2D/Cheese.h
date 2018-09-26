#pragma once
#include "Agent.h"
class Grid;

class Cheese : public Agent
{
public:
	Cheese(Vector2 v2Tranform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture, Grid* pGrid);
	~Cheese();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	void ChangePos();

	Grid* m_pGrid;
};

