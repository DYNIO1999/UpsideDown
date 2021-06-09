#ifndef _LOST_GAME_STATE_HPP_
#define _LOST_GAME_STATE_HPP_
#include "State.hpp"
#include "../StatesData/LostStateData.hpp"
#include "../GUI/Button.hpp"
class LostGameState:public StateI {
public:
	LostGameState(GameEngine* engine_ptr);
	~LostGameState();
	void Input();
	void Update();
	void Draw();
	LostStateData* m_LostData;
	Button* m_BackButton;
	Button* m_ExitButton;
	sf::Vector2f m_MousePosition_View;

private:
	void InitData();
	void UnloadData();
};
#endif // !_LOST_GAME_STATE_HPP_
