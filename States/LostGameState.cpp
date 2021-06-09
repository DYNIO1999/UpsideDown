#include "LostGameState.hpp"
#include <iostream>
LostGameState::LostGameState(GameEngine* UDEngine) {
	m_EnginePtr = UDEngine;
	InitData();
}
LostGameState::~LostGameState() {
	std::cout << "LOST STATE DESTRUCTOR" << '\n';
	UnloadData();
}
void LostGameState::Input()
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
void LostGameState::Update() {
	if (m_BackButton->ButtonUpdate()) {
		sf::Time delayTime = sf::seconds(0.1);
		sf::sleep(delayTime);
		m_EnginePtr->PopState();
		return;
	}
	if (m_ExitButton->ButtonUpdate()) {
		sf::Time delayTime = sf::seconds(0.1);
		sf::sleep(delayTime);
		m_EnginePtr->m_Window->close();
		return;
	}
}
void LostGameState::Draw() {
	m_EnginePtr->m_Window->draw(*m_LostData->m_BackgroundLost);
	m_EnginePtr->m_Window->draw(*m_LostData->m_TitleLost);
	m_BackButton->ButtonDraw(m_EnginePtr);
	m_ExitButton->ButtonDraw(m_EnginePtr);
}

void LostGameState::InitData() {
	m_LostData = new LostStateData;
	m_LostData->backgroundTexture = new sf::Texture;
	m_LostData->titleTexture = new sf::Texture;
	m_LostData->m_BackgroundLost = new sf::Sprite;
	m_LostData->m_TitleLost = new sf::Sprite;
	m_LostData->lostFont = new sf::Font;

	m_LostData->backgroundTexture->loadFromFile("./assets/BackgroundMenu.png");
	m_LostData->titleTexture->loadFromFile("./assets/you_lost.png");
	m_LostData->lostFont->loadFromFile("./assets/MenuFont.ttf");
	m_LostData->m_BackgroundLost->setTexture(*m_LostData->backgroundTexture);
	m_LostData->m_TitleLost->setTexture(*m_LostData->titleTexture);

	m_LostData->m_BackgroundLost->setPosition(sf::Vector2f(0.0, 0.0));
	m_LostData->m_TitleLost->setScale(sf::Vector2f(0.7,0.7));
	m_LostData->m_TitleLost->setPosition(sf::Vector2f((m_EnginePtr->m_Window->getSize().x / 2) - 377.0, 100));


	Colors temp;
	temp.pressedColor = sf::Color(70, 70, 70, 200);
	temp.hoverColor = sf::Color(20, 20, 20, 200);
	temp.idleColor = sf::Color(150, 150, 150, 200);
	float tempCalculateWidth = 2.28 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateHeight = 0.51 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculateX = 5.26 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateY = 1.25 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);

	m_BackButton = new Button(tempCalculateX, tempCalculateY*2, tempCalculateWidth, tempCalculateHeight, *m_LostData->lostFont, "Menu", temp);
	m_ExitButton = new Button(tempCalculateX, tempCalculateY *3, tempCalculateWidth, tempCalculateHeight, *m_LostData->lostFont, "Exit", temp);
}
void LostGameState::UnloadData() {
	std::cout << "LOST STATE DESTRUCTOR 2" << '\n';
	delete m_LostData;
	delete m_ExitButton;
	delete m_BackButton;
}
