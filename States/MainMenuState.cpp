#include "MainMenuState.hpp"
#include "OptionsMenuState.hpp"
#include "HelpMenuState.hpp"
#include "GameState.hpp"
#include <iostream>
MainMenuState::MainMenuState(GameEngine* UDEngine){
    m_EnginePtr = UDEngine;
	InitData();
}
MainMenuState::~MainMenuState() {
	std::cout << "MAIN MENU STATE DESTRUCTOR" << '\n';
	UnloadData();
}
void MainMenuState::Input() 
{
	sf::Event event;
	m_MousePosition_View = m_EnginePtr->m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_EnginePtr->m_Window));
	while (m_EnginePtr->m_Window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_EnginePtr->m_Window->close();

		}
		m_PlayButton->ButtonInput(m_MousePosition_View);
		m_HelpButton->ButtonInput(m_MousePosition_View);
		m_SettingsButton->ButtonInput(m_MousePosition_View);
		m_ExitButton->ButtonInput(m_MousePosition_View);
		//std::cout<<
	}
}
void MainMenuState::Update() {
	if (m_PlayButton->ButtonUpdate()) {
		sf::Time delayTime = sf::seconds(0.1);
		sf::sleep(delayTime);
		m_EnginePtr->PushState(new GameState(m_EnginePtr));
		return;
	}
	if(m_SettingsButton->ButtonUpdate()){
		sf::Time delayTime = sf::seconds(0.1);
	    sf::sleep(delayTime);
		m_EnginePtr->ChangeState(new OptionsMenuState(m_EnginePtr));
		return; 
	}
	if (m_HelpButton->ButtonUpdate()) {
		sf::Time delayTime = sf::seconds(0.1);
		sf::sleep(delayTime);
		m_EnginePtr->ChangeState(new HelpMenuState(m_EnginePtr));

		return;
	}
	if(m_ExitButton->ButtonUpdate()){
		sf::Time delayTime = sf::seconds(0.1);
		sf::sleep(delayTime);
		m_EnginePtr->m_Window->close();
		return;
	}
}
void MainMenuState::Draw() {
	m_EnginePtr->m_Window->draw(*m_Menu->m_BackgroundMenu);
	m_EnginePtr->m_Window->draw(*m_Menu->m_MenuTitle);
	m_PlayButton->ButtonDraw(m_EnginePtr);
	m_SettingsButton->ButtonDraw(m_EnginePtr);
	m_ExitButton->ButtonDraw(m_EnginePtr);
	m_HelpButton->ButtonDraw(m_EnginePtr);
}

void MainMenuState::InitData() {
	m_Menu = new MainMenuData;
	m_Menu->m_MenuTitle = new sf::Sprite;
	m_Menu->m_BackgroundMenu = new sf::Sprite;
	m_Menu->menuFont = new sf::Font;
	m_Menu->menuBackground = new sf::Texture;
	m_Menu->menuTitle = new sf::Texture;
	m_Menu->menuBackground->loadFromFile("./assets/BackgroundMenu.png");
	m_Menu->menuTitle->loadFromFile("./assets/MenuTitle.png");
	m_Menu->menuFont->loadFromFile("./assets/MenuFont.ttf");
	Colors temp;
	temp.pressedColor = sf::Color(70, 70, 70, 200);
	temp.hoverColor = sf::Color(20, 20, 20, 200);
	temp.idleColor = sf::Color(150, 150, 150, 200);
	float tempCalculateWidth = 2.28*((m_EnginePtr->m_Window->getSize().x*100)/1280);
	float tempCalculateHeight = 0.51 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculateX = 5.26* ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateY = 2.25 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculate2Y = 1.02 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculate3Y = 0.8* ((m_EnginePtr->m_Window->getSize().y * 100) / 720);

	m_PlayButton = new Button(tempCalculateX, tempCalculateY, tempCalculateWidth, tempCalculateHeight, *m_Menu->menuFont, "Play", temp);
	m_SettingsButton = new Button(tempCalculateX, tempCalculateY+tempCalculate3Y, tempCalculateWidth, tempCalculateHeight, *m_Menu->menuFont, "Options", temp);
	m_HelpButton = new Button(tempCalculateX, tempCalculateY + tempCalculate3Y*2, tempCalculateWidth, tempCalculateHeight, *m_Menu->menuFont, "Help", temp);
	m_ExitButton = new Button(tempCalculateX, tempCalculateY+ tempCalculate3Y*3, tempCalculateWidth, tempCalculateHeight, *m_Menu->menuFont, "Exit", temp);
	m_Menu->m_BackgroundMenu->setTexture(*m_Menu->menuBackground);
	m_Menu->m_BackgroundMenu->setPosition(sf::Vector2f(0.f, 0.f));
	m_Menu->m_MenuTitle->setTexture(*m_Menu->menuTitle);
	m_Menu->m_MenuTitle->setPosition(sf::Vector2f((m_EnginePtr->m_Window->getSize().x /2)- 440.f, tempCalculate2Y));
	m_Menu->m_MenuTitle->setScale(0.7, 0.7);
}
void MainMenuState::UnloadData() {
	delete m_Menu;
	m_Menu = nullptr;
	delete m_PlayButton;
	m_PlayButton = nullptr;
	delete m_SettingsButton;
	m_SettingsButton = nullptr;
	delete m_ExitButton;
	m_ExitButton = nullptr;
	delete m_HelpButton;
	m_HelpButton = nullptr;
}