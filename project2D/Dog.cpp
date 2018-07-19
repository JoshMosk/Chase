#include "Dog.h"
#include "Human.h"
#include "Vector2.h"
#include "FlockingBehaviour.h"

Dog::Dog(Vector2 v2Tranform, float fRadiansRotation, float fSpeed, float fMaxSpeed, aie::Texture* pTexture, Human* pHuman)
	: Agent(v2Tranform, fRadiansRotation, fSpeed, fMaxSpeed, pTexture)
{
	m_pHuman = pHuman;
}

Dog::~Dog()
{
}

void Dog::Update(float fDeltaTime)
{

}

void Dog::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_m3Transform);
}
