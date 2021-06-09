#ifndef _PAUSE_STATE_DATA_HPP_
#define _PAUSE_STATE_DATA_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct PauseData {
	~PauseData() {
		delete backgroundTexture;
		delete m_BackgroundPause;
		delete titleTexture;
		delete m_TitlePause;
		delete pauseFont;
	}
	sf::Texture* backgroundTexture;
	sf::Texture* titleTexture;
	sf::Font* pauseFont;
	sf::Sprite* m_BackgroundPause;
	sf::Sprite* m_TitlePause;
};

#endif