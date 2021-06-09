#ifndef _GAME_STATE_HPP_
#define _GAME_STATE_HPP_
#include "State.hpp"
#include "../StatesData/GameStateData.hpp"
enum ColisionStates
{
	DEFAULT = 0,
	LOSTGAME = 1,
	WONGAME =2,
	ESC =3,
};
class GameState:public StateI
{
public:
	GameState(GameEngine* engine_ptr);
	~GameState();
	void Input();
	void Update();
	void Draw();
    sf::RectangleShape* Player;
	sf::RectangleShape* LostDetection;
	sf::RectangleShape* WonDetection;
	GameStateData* m_GameData;
	sf::Vector2f m_MousePosition_View;
	int check;

private:
	void InitData();
	void UnloadData();
};
#endif 

