#ifndef _OPTIONS_MENU_STATE_
#define _OPTIONS_MENU_STATE_
#include "State.hpp"
#include "../GUI/Button.hpp"
#include "../StatesData/OptionsMenuData.hpp"
class OptionsMenuState:public StateI
{
public:
	OptionsMenuState(GameEngine* engine_ptr);
	~OptionsMenuState();
	void Input();
	void Update();
	void Draw();
	OptionsMenuData* m_Options;
	Button* m_SoundOFF;
	Button* m_SoundON;
	Button* m_Resoultion1;
	Button* m_Resoultion2;
	Button* m_ResoultionFullscreen;
	Button* m_BackButton;
	sf::Vector2f m_MousePosition_View;
private:
	void InitData();
	void UnloadData();
	void SaveSettings(bool fullscreen);
	void SaveSettings(int screen_w, int screen_h);
};
#endif // !_OPTIONS_MENU_STATE_
