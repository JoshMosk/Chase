#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <time.h>
#include <iostream>
#include "PatrolBehaviour.h"
#include "FlockingBehaviour.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	srand(time(NULL));

	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/barrelBlue.png");
	m_shipTexture = new aie::Texture("./textures/barrelBeige.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_human = new Human(Vector2(100,300), 0, 100, 50, m_shipTexture);
	m_dog.push_back(new Dog(Vector2(300, 600), 0, 200, 50, m_texture, m_human));
	m_dog.push_back(new Dog(Vector2(320, 600), 0, 200, 50, m_texture, m_human));
	m_dog.push_back(new Dog(Vector2(340, 600), 0, 200, 50, m_texture, m_human));
	m_dog.push_back(new Dog(Vector2(360, 600), 0, 200, 50, m_texture, m_human));

	for (int i = 0; i < m_dog.size(); i++)
	{
		for (int j = 0; j < m_dog.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			m_dog[i]->m_pFlock->AddToFlock(m_dog[j]);
		}
		std::cout << m_dog.size() << std::endl;
	}

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	for (int i = 0; i < m_dog.size(); i++)
	{
		delete m_dog[i];
	}
	delete m_human;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_human->Update(deltaTime);
	for (int i = 0; i < m_dog.size(); i++)
	{
		m_dog[i]->Update(deltaTime);
	}

	//std::cout << m_human->m_patrol->m_path[m_human->m_patrol->nCurrentPoint].x << " ";
	//std::cout << m_human->m_patrol->m_path[m_human->m_patrol->nCurrentPoint].y << std::endl;
	//std::cout << m_dog->GetTargetPos().x << ", " << m_dog->GetTargetPos().y << std::endl;
	//std::cout << m_dog[0]->m_pFlock->GetFlock().size() << std::endl;
	//std::cout << m_dog->m_fSpeed << ", " << m_dog->GetMaxSpeed() << std::endl;
	//std::cout << m_dog[0]->GetPosition().x << ", " << m_dog[0]->GetPosition().y << std::endl;

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->setRenderColour(0x444444ff);
	m_2dRenderer->drawCircle(0, 0, 5);
	m_2dRenderer->setRenderColour(0xffffffff);

	m_human->Draw(m_2dRenderer);

	for (int i = 0; i < m_dog.size(); i++)
	{
		m_dog[i]->Draw(m_2dRenderer);
	}

	//m_2dRenderer->drawBox(m_dog->GetPosition().x, m_dog->GetPosition().y, 5, 5, m_dog->GetRotation());
	//// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	//// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	//// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(200, 600, 5, 5, m_timer);
	m_2dRenderer->drawBox(600, 600, 5, 5, m_timer);
	m_2dRenderer->drawBox(600, 200, 5, 5, m_timer);
	m_2dRenderer->drawBox(200, 200, 5, 5, m_timer);

	//// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}