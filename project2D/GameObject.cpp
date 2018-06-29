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

void GameObject::SetRotation(float fRadians)		//sets both matrix rotation and a float variable for reference
{
	m_m3Transform.setRotateZ(fRadians);
	m_fRotation = fRadians;
}

float GameObject::GetRotation()		//returns m_fRotation float as extracting rotation from a matrix is too convoluted
{
	return m_fRotation;
}