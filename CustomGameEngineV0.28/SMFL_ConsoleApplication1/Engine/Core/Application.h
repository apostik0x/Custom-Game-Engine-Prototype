#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../Graphics/Entity.h"
#include "InputManager.h"

class Engine
{
public:
    Engine();
    ~Engine();

    // Motoru başlatacak olan ana fonksiyonumuz
    void run();

private:
    // Oyun döngüsünün 3 ana aşaması
    void processEvents();
    void update(float dt);
    void render();

    // SFML penceremiz ve zaman tutucumuz
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    sf::View m_camera;

    std::vector<std::unique_ptr<Entity>> m_entities;
    
    Input m_input;  

};