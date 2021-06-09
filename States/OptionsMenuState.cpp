#include "OptionsMenuState.hpp"
#include "MainMenuState.hpp"
#include <iostream>
OptionsMenuState::OptionsMenuState(GameEngine* engine_ptr) {
	m_EnginePtr = engine_ptr;
	InitData();
}
OptionsMenuState::~OptionsMenuState() {
	std::cout << "OPTIONS MENU DESTRUCTOR" << '\n';
	UnloadData();
}
void OptionsMenuState::Input() {
	sf::Event event;
	m_MousePosition_View = m_EnginePtr->m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_EnginePtr->m_Window));
	while (m_EnginePtr->m_Window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_EnginePtr->m_Window->close();

		}
	m_SoundON->ButtonInput(m_MousePosition_View);
	m_SoundOFF->ButtonInput(m_MousePosition_View);
	m_BackButton->ButtonInput(m_MousePosition_View);
	m_ResoultionFullscreen->ButtonInput(m_MousePosition_View);
    m_Resoultion1->ButtonInput(m_MousePosition_View);
    m_Resoultion2->ButtonInput(m_MousePosition_View);
	}
}
void OptionsMenuState::Update() {
	if (m_BackButton->ButtonUpdate()) {
		m_EnginePtr->ChangeState(new MainMenuState(m_EnginePtr));
		return;
	}
	if (m_Resoultion1->ButtonUpdate()) {
		const int screen_width = 1280;
		const int screen_height = 720;
		SaveSettings(screen_width, screen_height);
		return;
	}
	if (m_Resoultion2->ButtonUpdate()) {
		const int screen_width = 1600;
		const int screen_height = 900;
		SaveSettings(screen_width, screen_height);
		return;
	}
	if (m_ResoultionFullscreen->ButtonUpdate()) {
		bool fullscreen = true;
		SaveSettings(fullscreen);
		return;
	}
	if (m_SoundON->ButtonUpdate()) {
		//
		return;
	}
	if (m_SoundOFF->ButtonUpdate()) {
		return;
	}
}
void OptionsMenuState::Draw() {
	m_EnginePtr->m_Window->draw(*m_Options->m_BackgroundOptionsMenu);
	m_EnginePtr->m_Window->draw(*m_Options->m_TitleOptionsMenu);
	m_SoundON->ButtonDraw(m_EnginePtr);
	m_SoundOFF->ButtonDraw(m_EnginePtr);
	m_BackButton->ButtonDraw(m_EnginePtr);
	m_ResoultionFullscreen->ButtonDraw(m_EnginePtr);
	m_Resoultion1->ButtonDraw(m_EnginePtr);
	m_Resoultion2->ButtonDraw(m_EnginePtr);
}
void OptionsMenuState::InitData() {
	m_Options = new OptionsMenuData;
	m_Options->optionsBackground = new sf::Texture;
	m_Options->m_BackgroundOptionsMenu = new sf::Sprite;
	m_Options->optionsFont = new sf::Font;
	m_Options->optionsTitle = new sf::Texture;
	m_Options->m_TitleOptionsMenu = new sf::Sprite;

	float tempCalculateWidth = 2.28 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateHeight = 0.51 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculateX = 5.26 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateY = 2.2 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculate2Y =  1.02* ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculate3Y = 0.8 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	Colors temp;
	m_Options->optionsBackground->loadFromFile("./assets/BackgroundMenu.png");
	m_Options->optionsTitle->loadFromFile("./assets/options.png");
	m_Options->optionsFont->loadFromFile("./assets/MenuFont.ttf");
	temp.pressedColor = sf::Color(70, 70, 70, 200);
	temp.hoverColor = sf::Color(20, 20, 20, 200);
	temp.idleColor = sf::Color(150, 150, 150, 200);
	m_SoundON = new Button(tempCalculateX - tempCalculateWidth/2, tempCalculateY, tempCalculateWidth, tempCalculateHeight, *m_Options->optionsFont, "Sound ON", temp);
	m_SoundOFF = new Button(tempCalculateX + tempCalculateWidth/2, tempCalculateY, tempCalculateWidth, tempCalculateHeight, *m_Options->optionsFont, "Sound OFF", temp);
	m_Resoultion1 = new Button(tempCalculateX - tempCalculateWidth/2, tempCalculateY+tempCalculate3Y, tempCalculateWidth, tempCalculateHeight, *m_Options->optionsFont, "1280x720", temp);
	m_Resoultion2 = new Button(tempCalculateX + tempCalculateWidth / 2, tempCalculateY +tempCalculate3Y, tempCalculateWidth, tempCalculateHeight, *m_Options->optionsFont, "1600x900", temp);
	m_ResoultionFullscreen= new Button(tempCalculateX, tempCalculateY +tempCalculate3Y *2,tempCalculateWidth, tempCalculateHeight, *m_Options->optionsFont, "Fullscreen", temp);
	m_BackButton = new Button(tempCalculateX, tempCalculateY +tempCalculate3Y * 4, tempCalculateWidth, tempCalculateHeight, *m_Options->optionsFont, "Back", temp);
	m_Options->m_BackgroundOptionsMenu->setTexture(*m_Options->optionsBackground);
	m_Options->m_BackgroundOptionsMenu->setPosition(sf::Vector2f(0.f, 0.f));
	m_Options->m_TitleOptionsMenu->setTexture(*m_Options->optionsTitle);
	m_Options->m_TitleOptionsMenu->setScale(sf::Vector2f(0.9, 0.9));
	m_Options->m_TitleOptionsMenu->setPosition(sf::Vector2f((m_EnginePtr->m_Window->getSize().x / 2) - 225.f, tempCalculate2Y));
}
void OptionsMenuState::UnloadData() {
	std::cout << "OPTIONS MENU DESTRUCTOR 2" << '\n';
	delete m_Options;
	m_Options = nullptr;
	delete m_BackButton;
	m_BackButton = nullptr;
	delete m_SoundON;
	m_SoundON = nullptr;
	delete m_SoundOFF;
	m_SoundOFF = nullptr;
	delete m_Resoultion1;
	m_Resoultion1 = nullptr;
	delete m_Resoultion2;
	m_Resoultion2 = nullptr;
	delete m_ResoultionFullscreen;
	m_ResoultionFullscreen = nullptr;
}
void OptionsMenuState::SaveSettings(bool fullscreen) {
	std::ofstream config("./GameSettings.ini", std::ios::out | std::ios::trunc);
	if (config.is_open()) {
		config << m_EnginePtr->m_WindowVideoMode->width << std::endl;
		config << m_EnginePtr->m_WindowVideoMode->height << std::endl;
		config << fullscreen << std::endl;
	}
	config.close();
}
void OptionsMenuState::SaveSettings(int screen_w, int screen_h) {
	std::ofstream config("./GameSettings.ini", std::ios::out | std::ios::trunc);
	if (config.is_open()) {
		config << screen_w<< std::endl;
		config << screen_h << std::endl;
		config << 0 << std::endl;
	}
	config.close();
}
