#ifndef _GAME_ENGINE_HPP_
#define _GAME_ENGINE_HPP_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
class StateI;
enum WindowSize {
	WINDOW_WIDTH =1280,
	WINDOW_HEIGHT =720,
};
class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void Run();
	void Input();
	void Update();
	void Draw();
	void ChangeState(StateI* state);
	void PushState(StateI* state);
	void PopState();
	void SaveSettings();
	bool ReadSettings();
	sf::RenderWindow* m_Window;
	sf::Vector2f m_WindowSize;
	sf::VideoMode* m_WindowVideoMode;
	std::vector<StateI*> m_States; //Stos
	float m_deltaTime;
	sf::Clock m_dtClock;
	void UpdateDeltaTime();
	std::string filename;
private:
};
#endif