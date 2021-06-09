#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_
#include <SFML/Graphics.hpp>
#include <string>
enum BUTTON_STATES {
	BUTTON_PRESSED,
	BUTTON_HOVER,
	BUTTON_IDLE,
};
struct Colors{
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressedColor;
};
class Button {
public:
	Button(float x, float y, float width, float height, sf::Font font, std::string text, Colors buttoncolors) {
		m_ButtonColors = new Colors;
		m_ButtonColors->pressedColor = buttoncolors.pressedColor;
		m_ButtonColors->hoverColor = buttoncolors.hoverColor;
		m_ButtonColors->idleColor = buttoncolors.idleColor;
		m_ButtonShape.setPosition(sf::Vector2f(x, y));
		m_ButtonShape.setSize(sf::Vector2f(width, height));
		m_ButtonShape.setOutlineThickness(2.f);
		m_ButtonShape.setOutlineColor(sf::Color::Black);
	    m_ButtonFont = font;
		m_ButtonText.setFont(m_ButtonFont);
		m_ButtonText.setString(text);
		m_ButtonText.setFillColor(sf::Color::White);
		m_ButtonText.setCharacterSize(40);
		m_ButtonText.setScale(sf::Vector2f(1.2, 1.2));
		m_ButtonText.setOutlineColor(sf::Color::Black);
		m_ButtonText.setOutlineThickness(1.f);
		m_ButtonText.setLetterSpacing(2.f);
		m_ButtonText.setPosition(m_ButtonShape.getPosition().x +(m_ButtonShape.getGlobalBounds().width / 2.f)-(m_ButtonText.getGlobalBounds().width/2.f),
			m_ButtonShape.getPosition().y +(m_ButtonShape.getGlobalBounds().height / 2.f)-(m_ButtonText.getGlobalBounds().height/2.f)-12.5);
		m_ButtonShape.setFillColor(m_ButtonColors->idleColor);
		m_ButtonState = BUTTON_IDLE;
	};
	~Button() {
		std::cout << "Button destruction\n";
		delete m_ButtonColors;
		m_ButtonColors = nullptr;
	};
	void ButtonInput(sf::Vector2f mousepos) {
		m_ButtonState = BUTTON_IDLE;
		if (m_ButtonShape.getGlobalBounds().contains(mousepos)) {
			m_ButtonState = BUTTON_HOVER;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				m_ButtonState =BUTTON_PRESSED;
			}
		}
	}
	bool ButtonUpdate() {
		if (m_ButtonState == BUTTON_IDLE) {
			m_ButtonShape.setFillColor(m_ButtonColors->idleColor);
			return false;
		}
		else if (m_ButtonState == BUTTON_HOVER) {
			m_ButtonShape.setFillColor(m_ButtonColors->hoverColor);
			return false;
		}
		else if (m_ButtonState == BUTTON_PRESSED) {
			m_ButtonShape.setFillColor(m_ButtonColors->pressedColor);
			return true;
		}
		return false;
	}
	void ButtonDraw(GameEngine* enginePtr) {
		enginePtr->m_Window->draw(m_ButtonShape);
		enginePtr->m_Window->draw(m_ButtonText);
	}
	public:
	sf::RectangleShape m_ButtonShape;
	sf::Font m_ButtonFont;
	sf::Text m_ButtonText;
	Colors* m_ButtonColors;
	int m_ButtonState; 
};

#endif // !_BUTTON_HPP_
