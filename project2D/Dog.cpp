#include "Dog.h"
#include "Human.h"
#include "Vector2.h"
#include "DogDecisionMaking.h"
#include "FlockDecision.h"
#include "FlockingBehaviour.h"
#include "Mouse.h"

Dog::Dog(Vector2 v2Tranform, float fRadiansRotation, float fSpeed, float fMaxSpeed, aie::Texture* pTexture, Human* pHuman, Mouse* pMouse, Grid* pGrid)
	: Agent(v2Tranform, fRadiansRotation, fSpeed, fMaxSpeed, pTexture)
{
	m_pMouse = pMouse;

	m_pDecisionTree = new DogDecisionMaking(this, pHuman, (Agent*)pMouse, pGrid);
}

Dog::~Dog()
{
	delete m_pDecisionTree;
}

void Dog::Update(float fDeltaTime)
{
	SetTargetPos(m_pDecisionTree->Update(fDeltaTime));
	//SetTargetPos(m_pDecisionTree->m_pFlockHuman->m_v2TargetDirection);//->m_pFlock->Update(fDeltaTime));
	Agent::Update(fDeltaTime);	

	Vector2 mag = GetPosition() - m_pMouse->GetPosition();
	if (mag.squaredMagnitude() < 100)
	{
		m_pMouse->Die();
	}
}

void Dog::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_m3Transform);
}
