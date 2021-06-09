#ifndef _WON_GAME_STATE_HPP_
#define _WON_GAME_STATE_HPP_
#include "State.hpp"
#include "../StatesData/WonStateData.hpp"
#include "../GUI/Button.hpp"
class WonGameState:public StateI {
public:
	WonGameState(GameEngine* engine_ptr);
	~WonGameState();
	void Input();
	void Update();
	void Draw();
	WonStateData* m_WonData;
	Button* m_BackButton;
	Button* m_ExitButton;
	sf::Vector2f m_MousePosition_View;

private:
	void InitData();
	void UnloadData();
};

#endif 
