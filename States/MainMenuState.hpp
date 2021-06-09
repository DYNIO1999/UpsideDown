#ifndef _MAIN_MENU_STATE_HPP_
#define _MAIN_MENU_STATE_HPP_
#include "State.hpp"
#include "../GUI/Button.hpp"
#include "../StatesData/MainMenuData.hpp"
class MainMenuState: public StateI
{
public:
	MainMenuState(GameEngine* UDEngine);
	~MainMenuState();
	void Input();
	void Update();
	void Draw();
	Button* m_HelpButton;
	Button* m_PlayButton;
	Button* m_SettingsButton;
	Button* m_ExitButton;
	MainMenuData* m_Menu;
	sf::Vector2f m_MousePosition_Screen;
	sf::Vector2i m_MousePosition_Window;
	sf::Vector2f m_MousePosition_View;
private:
	void InitData();
	void UnloadData();
};
#endif
