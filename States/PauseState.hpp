#ifndef _PAUSE_STATE_HPP_
#define _PAUSE_STATE_HPP_
#include "State.hpp"
#include "../GUI/Button.hpp"
#include "../StatesData/PauseStateData.hpp"
class PauseState :public StateI
{
public:
	PauseState(GameEngine* engine_ptr);
	~PauseState();
	void Input();
	void Update();
	void Draw();
	PauseData* m_PauseData;
	Button* m_BackButton;
	Button* m_ExitButton;
	sf::Vector2f m_MousePosition_View;
private:
	void InitData();
	void UnloadData();
};

#endif // !_PAUSE_STATE_HPP_
