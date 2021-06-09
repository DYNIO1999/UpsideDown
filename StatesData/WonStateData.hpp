#ifndef _WON_STATE_DATA_HPP_
#define _WON_STATE_DATA_HPP_

struct WonStateData {
	~WonStateData() {
		delete backgroundTexture;
		delete m_BackgroundWon;
		delete titleTexture;
		delete m_TitleWon;
		delete wonFont;
	}
	sf::Texture* backgroundTexture;
	sf::Texture* titleTexture;
	sf::Font* wonFont;
	sf::Sprite* m_BackgroundWon;
	sf::Sprite* m_TitleWon;
};
#endif // !_WON_STATE_DATA_HPP_

