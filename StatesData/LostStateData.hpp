#ifndef _LOST_STATE_DATA_HPP_
#define _LOST_STATE_DATA_HPP_

struct LostStateData {
	~LostStateData() {
		delete backgroundTexture;
		delete m_BackgroundLost;
		delete titleTexture;
		delete m_TitleLost;
		delete lostFont;
	}
	sf::Texture* backgroundTexture;
	sf::Texture* titleTexture;
	sf::Font* lostFont;
	sf::Sprite* m_BackgroundLost;
	sf::Sprite* m_TitleLost;
};
#endif // !_LOST_STATE_DATA_HPP_
