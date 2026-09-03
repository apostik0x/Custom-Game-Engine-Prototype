#include <SFML/System/Vector2.hpp>
#include "MathUtils.h"
#include "InputManager.h"

Input::Input()
  : m_mousePosition{0.0f, 0.0f}
  , m_keyboardInput{0.0f, 0.0f}
  

{



}
Input::~Input() {

}

sf::Vector2f Input::getMousePosition(sf::RenderWindow& window) {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        m_mousePosition = sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
    return m_mousePosition;
}

sf::Vector2f Input::getKeyboardInput() {

    m_keyboardInput = sf::Vector2f(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) m_keyboardInput.y -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) m_keyboardInput.y += 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) m_keyboardInput.x -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) m_keyboardInput.x += 1.0f;

    return EngineMath::normalize(m_keyboardInput);
}



void Input::setMousePosition(sf::Vector2f position) {
    m_mousePosition = position;
}

void Input::setKeyboardInput(sf::Vector2f input) {
    m_keyboardInput = input;
}