#include "Mouse.h"
#include "Cheese.h"
#include "Grid.h"

Mouse::Mouse(Vector2 v2Tranform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture, Cheese* pCheese, Grid* pGrid) : Agent(v2Tranform, fRadiansRotation, fMaxSpeed, fSpeed, pTexture)
{
	m_pSeek = new SeekDecision(this, pCheese, pGrid);
	m_pCheese = pCheese;
}

Mouse::~Mouse()
{
}
void Mouse::Update(float fDeltaTime)
{

	//m_pSeek->MakeDecision(fDeltaTime);

	//Agent::m_v2TargetPos = m_pSeek->m_v2TargetDirection;
	
	SetTargetPos(m_pSeek->MakeDecision(fDeltaTime)->m_v2TargetDirection);

	Agent::Update(fDeltaTime);

	Vector2 mag = GetPosition() - m_pCheese->GetPosition();
	if (mag.squaredMagnitude() < 100)
	{
		m_pCheese->ChangePos();
	}
}

void Mouse::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_m3Transform);
}

void Mouse::Die()
{
	SetPosition(Vector2(rand() % 1280, rand() % 720));
}