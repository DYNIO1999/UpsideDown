#ifndef _HELP_MENU_STATE_
#define _HELP_MENU_STATE_
#include "State.hpp"
#include "../GUI/Button.hpp"
#include "../StatesData/HelpMenuData.hpp"
class HelpMenuState :public StateI
{
public:
	HelpMenuState(GameEngine* engine_ptr);
	~HelpMenuState();
	void Input();
	void Update();
	void Draw();
	HelpMenuData* m_Help;
	Button* m_BackButton;
	Button* m_WButton;
	Button* m_SButton;
	Button* m_AButton;
	Button* m_DButton;
	Button* m_SpaceButton;
	Button* m_EscButton;
	Button* m_LeftButton;
	Button* m_RightButton;
	Button* m_WDescription;
	Button* m_SDescription;
	Button* m_ADescription;
	Button* m_DDescription;
	Button* m_SpaceDescription;
	Button* m_EscDescription;
	Button* m_LeftDescription;
	Button* m_RightDescription;

	sf::Vector2f m_MousePosition_View;
private:
	void InitData();
	void UnloadData();
};
#endif 

