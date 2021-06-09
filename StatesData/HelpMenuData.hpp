#ifndef _HELP_MENU_DATA_HPP_
#define _HELP_MENU_DATA_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
struct HelpMenuData
{
	~HelpMenuData() {
		delete helpBackground;
		delete helpTitle;
		delete m_HelpBackground;
		delete m_HelpTitle;
		delete m_HelpRect;
	}
	sf::Texture* helpBackground;
	sf::Texture* helpTitle;
	sf::Font* helpFont;
	sf::Sprite* m_HelpBackground;
	sf::Sprite* m_HelpTitle;
	sf::RectangleShape* m_HelpRect;
};
#endif