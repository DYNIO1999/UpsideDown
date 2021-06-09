#ifndef _GAME_STATE_DATA_HPP_
#define _GAME_STATE_DATA_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
struct  GameStateData
{
	~GameStateData() {
		delete backgroundTexture;
		delete m_BackgroundGame;
	}
	sf::Texture* backgroundTexture;
	sf::Sprite* m_BackgroundGame; //Tlo
};
#endif // !_MAIN_MENU_DATA_HPP_
