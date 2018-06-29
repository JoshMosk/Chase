#include "Agent.h"

Agent::Agent(Vector2 m3Tranform, float fRadiansRotation, float fMaxSpeed, aie::Texture* pTexture) 
		: GameObject(m3Tranform, fRadiansRotation, m_pTexture)		//sets up agent's max speed and calls the GameObject constructor
{
	m_fMaxSpeed = fMaxSpeed;
}

Agent::~Agent()
{
}

void Agent::Update(float fDeltaTime)
{

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
