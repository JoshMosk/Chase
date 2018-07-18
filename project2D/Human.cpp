#include "Human.h"
#include "PatrolBehaviour.h"

Human::Human(Vector2 v2Tranform, float fRadiansRotation, float fMaxSpeed, aie::Texture* pTexture)
	: Agent(v2Tranform, fRadiansRotation, fMaxSpeed, pTexture)
{
	m_patrol = new PatrolBehaviour(this);

	m_patrol->AddPatrolPoint(Vector2(600, 600));
	m_patrol->AddPatrolPoint(Vector2(200, 600));
}

Human::~Human()
{
	delete m_patrol;
}

void Human::Update(float fDeltaTime)
{
	m_patrol->Update(fDeltaTime, Vector2());

	Agent::Update(fDeltaTime);
}

void Human::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_m3Transform);
}