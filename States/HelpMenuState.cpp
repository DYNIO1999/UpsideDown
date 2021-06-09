#include "HelpMenuState.hpp"
#include "MainMenuState.hpp"
#include <iostream>
#include <string>
HelpMenuState::HelpMenuState(GameEngine* engine_ptr) {
	m_EnginePtr = engine_ptr;
	InitData();
}
HelpMenuState::~HelpMenuState() {
	std::cout << "HELP MENU DESTRUCTOR" << '\n';
	UnloadData();
}
void HelpMenuState::Input() {
	sf::Event event;
	m_MousePosition_View = m_EnginePtr->m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_EnginePtr->m_Window));
	while (m_EnginePtr->m_Window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_EnginePtr->m_Window->close();

		}

		m_BackButton->ButtonInput(m_MousePosition_View);
	}
}
void HelpMenuState::Update() {
	if (m_BackButton->ButtonUpdate()) {
		m_EnginePtr->ChangeState(new MainMenuState(m_EnginePtr));
		return;
	}
	
}
void HelpMenuState::Draw() {
	m_EnginePtr->m_Window->draw(*m_Help->m_HelpBackground);
	m_EnginePtr->m_Window->draw(*m_Help->m_HelpRect);
	m_EnginePtr->m_Window->draw(*m_Help->m_HelpTitle);
	m_WButton->ButtonDraw(m_EnginePtr);
	m_SButton->ButtonDraw(m_EnginePtr);
	m_AButton->ButtonDraw(m_EnginePtr);
	m_DButton->ButtonDraw(m_EnginePtr);
	m_SpaceButton->ButtonDraw(m_EnginePtr);
	m_EscButton->ButtonDraw(m_EnginePtr);
	m_LeftButton->ButtonDraw(m_EnginePtr);
	m_RightButton->ButtonDraw(m_EnginePtr);
	m_BackButton->ButtonDraw(m_EnginePtr);
	m_WDescription->ButtonDraw(m_EnginePtr);
	m_SDescription->ButtonDraw(m_EnginePtr);
	m_ADescription->ButtonDraw(m_EnginePtr);
	m_DDescription->ButtonDraw(m_EnginePtr);
	m_SpaceDescription->ButtonDraw(m_EnginePtr);
	m_EscDescription->ButtonDraw(m_EnginePtr);
	m_LeftDescription->ButtonDraw(m_EnginePtr);
	m_RightDescription->ButtonDraw(m_EnginePtr);
}
void HelpMenuState::InitData() {
	m_Help = new HelpMenuData;
	m_Help->helpBackground = new sf::Texture;
	m_Help->helpTitle= new sf::Texture;
	m_Help->helpFont = new sf::Font;
	m_Help->m_HelpBackground= new sf::Sprite;
	m_Help->m_HelpTitle = new sf::Sprite;
	m_Help->m_HelpRect = new sf::RectangleShape;

	float tempCalculateWidth = 2.3 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateHeight = 0.51 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculateX = 5.25 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateX2 = 4.1 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
	float tempCalculateY = 2.2 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculateY2 = 1.265 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculate2Y = 0.11 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	float tempCalculate3Y = 0;
	if (m_EnginePtr->m_Window->getSize().y < 800) {
		tempCalculate3Y = 0.09 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	}
	else {
		tempCalculate3Y = 0.25 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
	}

	m_Help->helpBackground->loadFromFile("./assets/BackgroundMenu.png");
	m_Help->helpTitle->loadFromFile("./assets/help.png");
	m_Help->helpFont->loadFromFile("./assets/MenuFont.ttf");
	Colors temp;
	Colors help;

	temp.pressedColor = sf::Color(70, 70, 70, 200);
	temp.hoverColor = sf::Color(20, 20, 20, 200);
	temp.idleColor = sf::Color(150, 150, 150, 200);
	help.hoverColor = sf::Color(20, 20, 20, 200);
	help.idleColor = sf::Color(20, 20, 20, 200);
	help.pressedColor = sf::Color(20, 20, 20, 200);

	m_BackButton = new Button(tempCalculateX, tempCalculateY*2.98, tempCalculateWidth, tempCalculateHeight, *m_Help->helpFont, "Back", temp);
    m_WButton= new Button(tempCalculateX2 /*+ (tempCalculateWidth * 0.125)*/, tempCalculateY2, tempCalculateWidth*0.5/**0.25*/, tempCalculateHeight, *m_Help->helpFont, "W", help);
    m_SButton= new Button(tempCalculateX2 /*+ (tempCalculateWidth * 0.125)*/, tempCalculateY2*1.5, tempCalculateWidth*0.5/**0.25*/, tempCalculateHeight, *m_Help->helpFont, "S", help);
	m_AButton= new Button(tempCalculateX2 /*+ (tempCalculateWidth * 0.125)*/, tempCalculateY2*2, tempCalculateWidth*0.5/**0.25*/, tempCalculateHeight, *m_Help->helpFont, "A", help);
    m_DButton= new Button(tempCalculateX2 /*+ (tempCalculateWidth * 0.125)*/, tempCalculateY2*2.5, tempCalculateWidth*0.5/**0.25*/, tempCalculateHeight, *m_Help->helpFont, "D", help);
    m_SpaceButton= new Button(tempCalculateX2, tempCalculateY2*3, tempCalculateWidth * 0.5, tempCalculateHeight, *m_Help->helpFont, "Space", help);
    m_EscButton= new Button(tempCalculateX2, tempCalculateY2*3.5, tempCalculateWidth * 0.5, tempCalculateHeight, *m_Help->helpFont, "Esc", help);
    m_LeftButton= new Button(tempCalculateX2, tempCalculateY2*4, tempCalculateWidth * 0.5, tempCalculateHeight, *m_Help->helpFont, "LMB", help);
    m_RightButton= new Button(tempCalculateX2, tempCalculateY2*4.5, tempCalculateWidth * 0.5, tempCalculateHeight, *m_Help->helpFont, "RMB", help);
	help.hoverColor = sf::Color(70, 70, 70, 200);
	help.idleColor = sf::Color(70, 70, 70, 200);
	help.pressedColor = sf::Color(70, 70,70, 200);
	std::string tempString = "to move up";
	m_WDescription= new Button(tempCalculateX2+ (tempCalculateWidth * 0.5)+1, tempCalculateY2, tempCalculateWidth * 1.5, tempCalculateHeight, *m_Help->helpFont, tempString, help);
	tempString = "to move down";
	m_SDescription= new Button(tempCalculateX2 + (tempCalculateWidth * 0.5)+1, tempCalculateY2 * 1.5, tempCalculateWidth * 1.5, tempCalculateHeight, *m_Help->helpFont, tempString, help);
	tempString = "to move left";
	m_ADescription= new Button(tempCalculateX2 + (tempCalculateWidth * 0.5)+1, tempCalculateY2 * 2, tempCalculateWidth * 1.5, tempCalculateHeight, *m_Help->helpFont, tempString, help);
	tempString = "to move right";
	m_DDescription= new Button(tempCalculateX2 + (tempCalculateWidth * 0.5)+1, tempCalculateY2 * 2.5, tempCalculateWidth * 1.5, tempCalculateHeight, *m_Help->helpFont, tempString, help);
	tempString = "to jump";
	m_SpaceDescription= new Button(tempCalculateX2 + (tempCalculateWidth * 0.5)+1, tempCalculateY2 * 3, tempCalculateWidth * 1.5, tempCalculateHeight, *m_Help->helpFont, tempString, help);
	tempString = "to pause game";
	m_EscDescription= new Button(tempCalculateX2 + (tempCalculateWidth * 0.5)+1, tempCalculateY2 * 3.5, tempCalculateWidth * 1.5, tempCalculateHeight, *m_Help->helpFont, tempString, help);
	tempString = "to use sword";
	m_LeftDescription= new Button(tempCalculateX2 + (tempCalculateWidth * 0.5)+1, tempCalculateY2 * 4, tempCalculateWidth * 1.5, tempCalculateHeight, *m_Help->helpFont, tempString, help);
	tempString = "to use crossbow";
	m_RightDescription= new Button(tempCalculateX2 + (tempCalculateWidth * 0.5)+1, tempCalculateY2 * 4.5, tempCalculateWidth * 1.5, tempCalculateHeight, *m_Help->helpFont, tempString, help);
	m_Help->m_HelpBackground->setTexture(*m_Help->helpBackground);
	m_Help->m_HelpBackground->setPosition(sf::Vector2f(0.f, 0.f));
	m_Help->m_HelpTitle->setTexture(*m_Help->helpTitle);
	m_Help->m_HelpTitle->setScale(sf::Vector2f(0.8, 0.7));
	m_Help->m_HelpTitle->setPosition(sf::Vector2f((m_EnginePtr->m_Window->getSize().x / 2) - 120, tempCalculate3Y));
	m_Help->m_HelpRect->setPosition(sf::Vector2f(tempCalculateX*0.56, tempCalculate2Y*10));
	m_Help->m_HelpRect->setSize(sf::Vector2f(tempCalculateWidth*3, tempCalculateHeight*10.29));
	m_Help->m_HelpRect->setFillColor(sf::Color(100, 100, 100, 200));
	m_Help->m_HelpRect->setOutlineColor(sf::Color(70, 70, 70, 200));
	m_Help->m_HelpRect->setOutlineThickness(10);
}
void HelpMenuState::UnloadData() {
	std::cout << "HELP MENU DESTRUCTOR 2" << '\n';
	delete m_Help;
	m_Help = nullptr;
	delete m_BackButton;
	m_BackButton = nullptr;
	delete m_WButton;
	m_WButton = nullptr;
	delete m_SButton;
	m_SButton =	nullptr;
	delete m_AButton;
	m_AButton = nullptr;
	delete m_DButton;
	m_DButton = nullptr;
	delete m_SpaceButton;
	m_SpaceButton = nullptr;
	delete m_EscButton;
	m_EscButton = nullptr;
	delete m_LeftButton;
	m_LeftButton = nullptr;
	delete m_RightButton;
	m_RightButton = nullptr;
	delete m_WDescription;
	m_WDescription = nullptr;
	delete m_SDescription;
	m_SDescription = nullptr;
	delete m_ADescription;
	m_ADescription = nullptr;
	delete m_DDescription;
	m_DDescription = nullptr;
	delete m_SpaceDescription;
    m_SpaceDescription = nullptr;
	delete m_EscDescription;
    m_EscDescription = nullptr;
	delete m_LeftDescription;
    m_LeftDescription = nullptr;
	delete m_RightDescription;
	m_RightDescription = nullptr;
}

