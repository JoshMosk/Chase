#include "Agent.h"
#include <math.h>

Agent::Agent(Vector2 m3Transform, float fRadiansRotation, float fMaxSpeed, float fSpeed, aie::Texture* pTexture)
	: GameObject(m3Transform, fRadiansRotation, pTexture)		//sets up agent's speed and max speed and calls the GameObject constructor
{
	m_fMaxSpeed = fMaxSpeed;
	m_fSpeed = fSpeed;

	m_v2TargetPos = m3Transform;
}

Agent::~Agent()
{
}

void Agent::Update(float fDeltaTime)
{
	//need to add non uniform movement
	//Vector2 v2NewVelocity = m_v2Velocity + m_v2TargetPos * fDeltaTime;
	m_v2Velocity = m_v2Velocity + m_v2TargetPos * m_fSpeed * fDeltaTime;

	GameObject::SetPosition(GameObject::GetPosition() + m_v2Velocity * fDeltaTime);
	//float fTurn = atan2(GetVelocity().y, GetVelocity().x);
	GameObject::SetRotation(atan2(m_v2Velocity.y, m_v2Velocity.x));//m_v2Velocity.dot(m_v2Velocity));
	//GameObject::m_m3Transform.setPosition(GameObject::m_m3Transform.GetPosition() + m_v2Velocity);
}

void Agent::Draw(aie::Renderer2D* pRenderer)		//draws texture of agent using matrix
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m_m3Transform);
}

void Agent::SetVelocity(Vector2 v2Velocity)
{
	m_v2Velocity = v2Velocity;
}

Vector2 Agent::GetVelocity()
{
	return m_v2Velocity;
}

float Agent::GetMaxSpeed()
{
	return m_fMaxSpeed;
}

void Agent::SetTargetPos(Vector2 v2NewTargetPos)
{
	m_v2TargetPos = v2NewTargetPos;
}

Vector2 Agent::GetTargetPos()
{
	return m_v2TargetPos;
}
