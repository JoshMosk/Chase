#include "Human.h"
#include "PatrolBehaviour.h"
#include "HumanDecisionMaking.h"
#include "Grid.h"

Human::Human(Vector2 v2Tranform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture, Agent* pMouse, Grid* pGrid)
	: Agent(v2Tranform, fRadiansRotation, fMaxSpeed, fSpeed, pTexture)
{
	m_pDecisionTree = new HumanDecisionMaking(this, pMouse, pGrid);
}

Human::~Human()
{
	delete m_pDecisionTree;
}

void Human::Update(float fDeltaTime)
{
	//Vector2 v2targetPos;
	//v2targetPos = m_pDecisionTree->Update(fDeltaTime);

	//Agent::m_v2TargetPos = v2targetPos;

	SetTargetPos(m_pDecisionTree->Update(fDeltaTime));

	Agent::Update(fDeltaTime);
}

void Human::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_m3Transform);
}