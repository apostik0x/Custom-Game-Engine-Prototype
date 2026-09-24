#pragma once

#include <SFML/System/Vector2.hpp>

namespace sf { class RenderWindow; }

class Input
{
public:
	Input();
	~Input();

	sf::Vector2f getMousePosition(sf::RenderWindow& window);
	sf::Vector2f getKeyboardInput();

	void setMousePosition(sf::Vector2f position);
	void setKeyboardInput(sf::Vector2f input);

private:
	sf::Vector2f m_mousePosition{ 0.0f, 0.0f };
	sf::Vector2f m_keyboardInput{ 0.0f, 0.0f };
};
