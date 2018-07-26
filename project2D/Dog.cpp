#include "Dog.h"
#include "Human.h"
#include "Vector2.h"
#include "FlockingBehaviour.h"

Dog::Dog(Vector2 v2Tranform, float fRadiansRotation, float fSpeed, float fMaxSpeed, aie::Texture* pTexture, Human* pHuman)
	: Agent(v2Tranform, fRadiansRotation, fSpeed, fMaxSpeed, pTexture)
{
	m_pFlock = new FlockingBehaviour(this);
	m_pFlock->AddToFlock(pHuman);
}

Dog::~Dog()
{
}

void Dog::Update(float fDeltaTime)
{
	SetTargetPos(m_pFlock->Update(fDeltaTime));
	Agent::Update(fDeltaTime);
}

void Dog::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_m3Transform);
}
