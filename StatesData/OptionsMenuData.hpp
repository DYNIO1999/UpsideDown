#ifndef _OPTIONS_MENU_DATA_HPP_
#define _OPTIONS_MENU_DATA_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
struct OptionsMenuData
{
	~OptionsMenuData() {
		delete optionsBackground;
		delete optionsTitle;
		delete optionsFont;
		delete m_BackgroundOptionsMenu;
		delete m_TitleOptionsMenu;
	}
	sf::Texture* optionsBackground;
	sf::Texture* optionsTitle;
	sf::Font* optionsFont;
	sf::Sprite* m_BackgroundOptionsMenu;
	sf::Sprite* m_TitleOptionsMenu;
};
#endif
