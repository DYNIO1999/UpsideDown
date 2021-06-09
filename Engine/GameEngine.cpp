#include "GameEngine.hpp"
#include "../States/MainMenuState.hpp"
void GameEngine::Run() {
	m_States.push_back(new MainMenuState(this));
	std::cout << m_States.size() << '\n';
	while (m_Window->isOpen())
	{
		UpdateDeltaTime();
		Input();
		Update();
		Draw();
	}
}
void GameEngine::Input() {
	if (!m_States.empty()) {
		m_States.back()->Input();

	}
	else {
		m_Window->close();
	}
}
void GameEngine::Update()
{
	std::cout << m_States.size() << '\n';
	if (!m_States.empty()){
		m_States.back()->Update(); //(top)

	}
	else {
		m_Window->close();
	}
}
void GameEngine::Draw() {
	if (!m_States.empty()) {
		m_Window->clear();
		m_States.back()->Draw();
		m_Window->display();
	}
	else {
		m_Window->close();
	}
}
GameEngine::GameEngine() {
	filename = "./GameSettings.ini";
	m_Window = new sf::RenderWindow;
	m_WindowVideoMode = new sf::VideoMode;
	m_Window->setFramerateLimit(60);
	m_Window->setVerticalSyncEnabled(false);
	bool fullscreen = false;
	if (!ReadSettings()) {
		m_WindowVideoMode->width = WINDOW_WIDTH;
		m_WindowVideoMode->height = WINDOW_HEIGHT;
		m_Window->create(*m_WindowVideoMode, "TheUppsideDown");
		std::ofstream config("./GameSettings.ini", std::ios::out | std::ios::trunc);
		if (config.is_open()) {
			config << m_WindowVideoMode->width<<std::endl;
			config << m_WindowVideoMode->height<<std::endl;
			config << fullscreen << std::endl;
		}
	    config.close();
	}
	else {
		std::ifstream config("./GameSettings.ini");
		if (config.is_open()) {
			config >> m_WindowVideoMode->width;
			config >> m_WindowVideoMode->height;
			config >> fullscreen;
		}
		config.close();
		if (fullscreen == true) {
			m_Window->create(*m_WindowVideoMode, "TheUppsideDown", sf::Style::Fullscreen);
		}
		else {
			m_Window->create(*m_WindowVideoMode, "TheUppsideDown");
		}
	}
}
GameEngine::~GameEngine() {
	std::cout << "Clearing Data!" << '\n';
	std::cout << m_States.size() << '\n';
	for (auto it = m_States.begin(); it != m_States.end(); it++) {
		delete *it;
	}
	m_States.clear();
	std::cout << m_States.size() << '\n';
	delete m_Window;
	m_Window = nullptr;
	delete m_WindowVideoMode;
	m_WindowVideoMode= nullptr;
	//stack
}
void GameEngine::ChangeState(StateI* state) {
	delete m_States.back();
	m_States.pop_back();
	m_States.push_back(state);
}
void GameEngine::PushState(StateI* state) {
	m_States.push_back(state);
}
void GameEngine::PopState() {
	delete m_States.back();
	m_States.pop_back();
}
void GameEngine::UpdateDeltaTime() {
	m_deltaTime = m_dtClock.restart().asSeconds();
	//system("cls");
	//std::cout <<"DeltaTime:"<<m_deltaTime << '\n';
}
void GameEngine::SaveSettings() {

}
bool GameEngine::ReadSettings() {
	if (std::ifstream(filename))
	{
		std::cout << "Exist Game" << '\n';
		return true;
	}
	else {
		std::cout << "Doesn't Exist'GameSettings.ini'" << '\n';

		return false;
	}
}