#include "Human.h"
#include "PatrolBehaviour.h"

Human::Human(Vector2 v2Tranform, float fRadiansRotation, float fSpeed, float fMaxSpeed, aie::Texture* pTexture)
	: Agent(v2Tranform, fRadiansRotation, fSpeed, fMaxSpeed, pTexture)
{
	m_patrol = new PatrolBehaviour(this);

	m_patrol->AddPatrolPoint(Vector2(200, 600));
	m_patrol->AddPatrolPoint(Vector2(600, 600));
	m_patrol->AddPatrolPoint(Vector2(600, 200));
	m_patrol->AddPatrolPoint(Vector2(200, 200));
}

Human::~Human()
{
	delete m_patrol;
}

void Human::Update(float fDeltaTime)
{
	Vector2 v2targetPos;
	v2targetPos = m_patrol->Update(fDeltaTime, Vector2());

	Agent::m_v2TargetPos = v2targetPos;

	Agent::Update(fDeltaTime);
}

void Human::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_m3Transform);
}