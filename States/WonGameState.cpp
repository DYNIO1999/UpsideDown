#include "WonGameState.hpp"
#include <iostream>
WonGameState::WonGameState(GameEngine* UDEngine) {
	m_EnginePtr = UDEngine;
	InitData();
}
WonGameState::~WonGameState() {
	std::cout << "WON STATE DESTRUCTOR" << '\n';
	UnloadData();
}
void WonGameState::Input()
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
void WonGameState::Update() {
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
void WonGameState::Draw() {
	m_EnginePtr->m_Window->draw(*m_WonData->m_BackgroundWon);
	m_EnginePtr->m_Window->draw(*m_WonData->m_TitleWon);
	m_BackButton->ButtonDraw(m_EnginePtr);
	m_ExitButton->ButtonDraw(m_EnginePtr);
}

void WonGameState::InitData() {
	m_WonData = new WonStateData;
	m_WonData->backgroundTexture = new sf::Texture;
	m_WonData->titleTexture = new sf::Texture;
	m_WonData->m_BackgroundWon = new sf::Sprite;
	m_WonData->m_TitleWon = new sf::Sprite;
	m_WonData->wonFont = new sf::Font;

	m_WonData->backgroundTexture->loadFromFile("./assets/BackgroundMenu.png");
	m_WonData->titleTexture->loadFromFile("./assets/you_won.png");
	m_WonData->wonFont->loadFromFile("./assets/MenuFont.ttf");
	m_WonData->m_BackgroundWon->setTexture(*m_WonData->backgroundTexture);
	m_WonData->m_TitleWon->setTexture(*m_WonData->titleTexture);

	m_WonData->m_BackgroundWon->setPosition(sf::Vector2f(0.0, 0.0));
	m_WonData->m_TitleWon->setScale(sf::Vector2f(0.9, 0.9));
	m_WonData->m_TitleWon->setPosition(sf::Vector2f((m_EnginePtr->m_Window->getSize().x / 2) - 385.f, 100));


	Colors temp;
	temp.pressedColor = sf::Color(70, 70, 70, 200);
	temp.hoverColor = sf::Color(20, 20, 20, 200);
	temp.idleColor = sf::Color(150, 150, 150, 200);
	float tempCalculateWidth = 2.28 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateHeight = 0.51 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculateX = 5.26 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateY = 1.25 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);

	m_BackButton = new Button(tempCalculateX, tempCalculateY*2, tempCalculateWidth, tempCalculateHeight, *m_WonData->wonFont, "Menu", temp);
	m_ExitButton = new Button(tempCalculateX, tempCalculateY *3, tempCalculateWidth, tempCalculateHeight, *m_WonData->wonFont, "Exit", temp);
}
void WonGameState::UnloadData() {
	std::cout << "WON STATE DESTRUCTOR 2" << '\n';
	delete m_WonData;
	delete m_ExitButton;
	delete m_BackButton;
}