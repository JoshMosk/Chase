#include "GameObject.h"

GameObject::GameObject(Vector2 v2Transform, float fRadiansRotation, aie::Texture* pTexture)
{
	m_fRotation = fRadiansRotation;
	m_m3Transform = v2Transform;
	m_pTexture = pTexture;
}

GameObject::~GameObject()
{
}

void GameObject::SetPosition(Vector2 v2Pos)
{
	m_m3Transform = v2Pos;
}

Vector2 GameObject::GetPosition()
{
	return m_m3Transform.GetPosition();
}

void GameObject::SetRotation(float fRadians)
{
	m_m3Transform.setRotateZ(fRadians);
	m_fRotation = fRadians;
}

float GameObject::GetRotation()
{
	return m_fRotation;
}