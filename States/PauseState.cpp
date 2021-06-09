#include "PauseState.hpp"
#include <iostream>
PauseState::PauseState(GameEngine* UDEngine) {
	m_EnginePtr = UDEngine;
	InitData();
}
PauseState::~PauseState() {
	std::cout << "Pause STATE DESTRUCTOR" << '\n';
	UnloadData();
}
void PauseState::Input()
{
	sf::Event event;
	m_MousePosition_View = m_EnginePtr->m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_EnginePtr->m_Window));
	while (m_EnginePtr->m_Window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_EnginePtr->m_Window->close();
		}
	}
	m_BackButton->ButtonInput(m_MousePosition_View);
	m_ExitButton->ButtonInput(m_MousePosition_View);
}
void PauseState::Update() {
	if (m_BackButton->ButtonUpdate()) {
		sf::Time delayTime = sf::seconds(0.1);
		sf::sleep(delayTime);
		m_EnginePtr->PopState();
		return;
	}
	if (m_ExitButton->ButtonUpdate()) {
		sf::Time delayTime = sf::seconds(0.1);
		sf::sleep(delayTime);
		m_EnginePtr->PopState();
		m_EnginePtr->PopState();
		return;
	}
}
void PauseState::Draw() {
	m_EnginePtr->m_Window->draw(*m_PauseData->m_BackgroundPause);
	m_EnginePtr->m_Window->draw(*m_PauseData->m_TitlePause);
	m_BackButton->ButtonDraw(m_EnginePtr);
	m_ExitButton->ButtonDraw(m_EnginePtr);
}

void PauseState::InitData() {
	m_PauseData = new PauseData;
	m_PauseData->backgroundTexture = new sf::Texture;
	m_PauseData->titleTexture = new sf::Texture;
	m_PauseData->m_BackgroundPause = new sf::Sprite;
	m_PauseData->m_TitlePause = new sf::Sprite;
	m_PauseData->pauseFont = new sf::Font;

	m_PauseData->backgroundTexture->loadFromFile("./assets/BackgroundMenu.png");
	m_PauseData->titleTexture->loadFromFile("./assets/Pause.png");
	m_PauseData->pauseFont->loadFromFile("./assets/MenuFont.ttf");
	m_PauseData->m_BackgroundPause->setTexture(*m_PauseData->backgroundTexture);
	m_PauseData->m_TitlePause->setTexture(*m_PauseData->titleTexture);

	m_PauseData->m_BackgroundPause->setPosition(sf::Vector2f(0.0, 0.0));
	m_PauseData->m_TitlePause->setPosition(sf::Vector2f((m_EnginePtr->m_Window->getSize().x / 2) - 227.f, 100));


	Colors temp;
	temp.pressedColor = sf::Color(70, 70, 70, 200);
	temp.hoverColor = sf::Color(20, 20, 20, 200);
	temp.idleColor = sf::Color(150, 150, 150, 200);
	float tempCalculateWidth = 2.28 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateHeight = 0.51 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculateX = 5.26 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateY = 1.25 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);

	m_BackButton = new Button(tempCalculateX, tempCalculateY*2, tempCalculateWidth, tempCalculateHeight, *m_PauseData->pauseFont, "Continue", temp);
	m_ExitButton = new Button(tempCalculateX, tempCalculateY*3, tempCalculateWidth, tempCalculateHeight, *m_PauseData->pauseFont, "Menu", temp);
}
void PauseState::UnloadData() {
	std::cout << "Pause STATE DESTRUCTOR 2" << '\n';
	delete m_PauseData;
	delete m_ExitButton;
	delete m_BackButton;
}