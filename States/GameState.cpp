#include "GameState.hpp"
#include <iostream>
#include "PauseState.hpp"
#include "LostGameState.hpp"
#include "WonGameState.hpp"
GameState::GameState(GameEngine* UDEngine) {
	m_EnginePtr = UDEngine;
	InitData();
}
GameState::~GameState() {
	std::cout << "GAME STATE DESTRUCTOR" << '\n';
	UnloadData();
}
void GameState::Input()
{
	sf::Event event;
	m_MousePosition_View = m_EnginePtr->m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_EnginePtr->m_Window));
	while (m_EnginePtr->m_Window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_EnginePtr->m_Window->close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Player->move(0.0, -20.0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Player->move(-20.0, 0.0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Player->move(0.0, 20.0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Player->move(20.0, 0.0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			check=ESC;
		}
	}
}
void GameState::Update() {
	if (check == ESC) {
		m_EnginePtr->PushState(new PauseState(m_EnginePtr));
		//m_EnginePtr->PopState();
		check = DEFAULT;
		return;
	}
	if (check == LOSTGAME) {
		m_EnginePtr->ChangeState(new LostGameState(m_EnginePtr));
		check = DEFAULT;
		return;
	}
	if (check == WONGAME) {
		m_EnginePtr->ChangeState(new WonGameState(m_EnginePtr));
		check = DEFAULT;
		return;
	}
	if (LostDetection->getGlobalBounds().intersects(Player->getGlobalBounds())) {
		std::cout << "Lost State!\n";
		check = LOSTGAME;
	}
	if (WonDetection->getGlobalBounds().intersects(Player->getGlobalBounds())) {
		std::cout << "Won State!\n";
		check = WONGAME;
	}

}
void GameState::Draw() {
	m_EnginePtr->m_Window->draw(*m_GameData->m_BackgroundGame);
	m_EnginePtr->m_Window->draw(*LostDetection);
	m_EnginePtr->m_Window->draw(*WonDetection);
	m_EnginePtr->m_Window->draw(*Player);
}

void GameState::InitData() {
	m_GameData = new GameStateData;
	m_GameData->backgroundTexture = new sf::Texture;
	m_GameData->m_BackgroundGame = new sf::Sprite;
	m_GameData->backgroundTexture->loadFromFile("./assets/PlayBackground.png");
	m_GameData->m_BackgroundGame->setTexture(*m_GameData->backgroundTexture);
	m_GameData->m_BackgroundGame->setPosition(sf::Vector2f(0.f, 0.f));
	Player = new sf::RectangleShape;
	LostDetection = new sf::RectangleShape;
	WonDetection = new sf::RectangleShape;
	Player->setSize(sf::Vector2f(50.0, 50.0));
	Player->setPosition(m_EnginePtr->m_Window->getSize().x / 2, m_EnginePtr->m_Window->getSize().y / 2);
	Player->setFillColor(sf::Color::Red);
	LostDetection->setFillColor(sf::Color::Yellow);
	LostDetection->setSize(sf::Vector2f(300.0, 300.0));
	LostDetection->setPosition(m_EnginePtr->m_Window->getSize().x / 4, m_EnginePtr->m_Window->getSize().y / 4);
	WonDetection->setFillColor(sf::Color::Green);
	WonDetection->setSize(sf::Vector2f(300.0, 300.0));
	WonDetection->setPosition(m_EnginePtr->m_Window->getSize().x -300.0, m_EnginePtr->m_Window->getSize().y /2);
	double tempScaleX = (1.0 * ((double)((m_EnginePtr->m_Window->getSize().x) / 1280.0)));
	double tempScaleY =( 1.0 *((double)((m_EnginePtr->m_Window->getSize().y) / 720.0)));
	m_GameData->m_BackgroundGame->setScale(sf::Vector2f(tempScaleX, tempScaleY));
	check = DEFAULT;
	//m_GameData->m_BackgroundGame->

}
void GameState::UnloadData() {
	std::cout << "GAME STATE DESTRUCTOR 2" << '\n';
	delete m_GameData;
	delete Player;
	delete LostDetection;
	delete WonDetection;
}