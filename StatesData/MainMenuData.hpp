#ifndef _MAIN_MENU_DATA_HPP_
#define _MAIN_MENU_DATA_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
struct  MainMenuData
{
	~MainMenuData() {
		delete menuBackground;
		delete menuFont;
		delete menuTitle;
		delete m_BackgroundMenu;
		delete m_MenuTitle;
	}
	sf::Texture* menuBackground;
	sf::Texture* menuTitle;
	sf::Font* menuFont;
	sf::Sprite* m_BackgroundMenu; //Tlo
	sf::Sprite* m_MenuTitle;
};
#endif // !_MAIN_MENU_DATA_HPP_
