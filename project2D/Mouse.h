#pragma once
#include "Agent.h"
#include "Vector2.h"
#include "SeekDecision.h"
class Cheese;

class Mouse : public Agent
{
public:
	Mouse(Vector2 v2Tranform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture, Cheese* pCheese, Grid* pGrid);
	~Mouse();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	void Die();

	SeekDecision* m_pSeek;
	Cheese* m_pCheese;
};

