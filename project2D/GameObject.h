#pragma once
#include <Renderer2D.h>
#include <Texture.h>
#include "Matrix3.h"

class GameObject
{
public:
	GameObject(Vector2 v2Transform, float fRadiansRotation, aie::Texture* pTexture);		//sets up gameobject position, rotation and texture
	virtual ~GameObject();

	virtual void Update(float fDeltaTime) = 0;		//pure virtual function for updating gameobjects
	virtual void Draw(aie::Renderer2D* pRenderer) = 0;		//pure virtual function for drawing gameobjects

	//position setters and getters
	void SetPosition(Vector2 v2Pos);
	Vector2 GetPosition();

	//rotation setters and getters
	void SetRotation(float fRadians);		//sets both matrix rotation and a float variable for reference
	float GetRotation();		//returns m_fRotation float as extracting rotation from a matrix is too convoluted

protected:
	Matrix3 m_m3Transform;		//gameobject matrix
	float m_fRotation;		//an extractable rotation for gameobject 
	aie::Texture* m_pTexture;		//a texture for gameobjects
};

