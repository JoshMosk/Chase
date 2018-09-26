#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Human.h"
#include "Dog.h"
#include <vector>
#include "Cheese.h"
#include "Mouse.h"
#include "Grid.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_mouseTexture;
	aie::Texture*		m_cheeseTexture;
	aie::Font*			m_font;

	Human* m_human;
	Dog* m_dog;
	Mouse* m_mouse;
	Cheese* m_cheese;
	Grid* m_grid;

	float m_cameraX, m_cameraY;
	float m_timer;
};