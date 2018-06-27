#pragma once
#include <Renderer2D.h>
#include <Texture.h>
#include "Matrix3.h"

class GameObject
{
public:
	GameObject(Vector2 v2Transform, float fRadiansRotation, aie::Texture* pTexture);
	virtual ~GameObject();

	virtual void Update(float fDeltaTime) = 0;
	virtual void Draw(aie::Renderer2D* pRenderer) = 0;

	void SetPosition(Vector2 v2Pos);
	Vector2 GetPosition();

	void SetRotation(float fRadians);
	float GetRotation();

protected:
	Matrix3 m_m3Transform;
	float m_fRotation;
	aie::Texture* m_pTexture;
};

