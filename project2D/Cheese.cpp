#include "Cheese.h"
#include "Grid.h"
#include "Node.h"

Cheese::Cheese(Vector2 v2Tranform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture, Grid* pGrid) : Agent(v2Tranform, fRadiansRotation, fMaxSpeed, fSpeed, pTexture)
{
	m_pGrid = pGrid;
	ChangePos();
}


Cheese::~Cheese()
{
}

void Cheese::Update(float fDeltaTime)
{

}

void Cheese::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_m3Transform);
}

void Cheese::ChangePos()
{
	//SetPosition(Vector2(rand() % 1280, rand() % 720));

	Node* pNode;
	do
	{
		pNode = m_pGrid->GetNodeByPos(Vector2(rand() % 1280, rand() % 720));
	} while (pNode->m_bBlocked);

	SetPosition(pNode->m_v2Pos);
}