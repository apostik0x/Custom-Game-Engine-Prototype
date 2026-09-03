#include "Application.h"
#include <iostream>
#include <algorithm>
#include "MathUtils.h"
#include "../Physics/Physics.h"

#include "InputManager.h"

float width = 980 , height = 540 ;

Engine::Engine()
    : m_window(sf::VideoMode({ static_cast<unsigned int>(width), static_cast<unsigned int>(height) }), "Scence1"),
      m_box1(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(0.0f, 0.0f), sf::Vector2f(50.0f, 50.0f), true),
      m_box2(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(0.0f, 0.0f), sf::Vector2f(100.0f, 100.0f), false)
      //m_box3(sf::Vector2f(900.0f, 50.0f), sf::Vector2f(0.0f, 0.0f), sf::Vector2f(30.0f, 30.0f), false)
{
    m_camera.setSize({ width, height });

	m_box1.setColor(sf::Color::Red);
	m_box2.setColor(sf::Color::Blue);
	//m_box3.setColor(sf::Color::Green);
    /*if (!m_box1.createEntity("GroundV1.png") || !m_box2.createEntity("GroundV1.png") || !m_box3.createEntity("GroundV1.png"))
    {
        std::cout << "Gorsel yuklenemedi! Dosya yolunu kontrol et." << std::endl;
    }*/
}

Engine::~Engine()
{
    //Motor kapanirken temizlenecek şeyler
}

void Engine::run()
{
    
    //Oyun Döngüsü (Game Loop)
    while (m_window.isOpen())
    {
        float dt = m_clock.restart().asSeconds();

        processEvents();
        update(dt);
        render();
    }
}

void Engine::processEvents()
{

    while (const auto event = m_window.pollEvent())
    {
        // Çarpıya basılırsa pencereyi kapat
        if (event->is<sf::Event::Closed>())
            m_window.close();
    }
}

void Engine::update(float dt)
{

    sf::Vector2f dir = m_input.getKeyboardInput();
	m_box1.setVelocity(dir * 200.0f);

	m_box1.update(dt);
    m_box2.update(dt);

	Physics::aabbCollisionHandle(m_box1, m_box2);


    sf::Vector2f pos1 = m_box1.getPosition();
    sf::Vector2f size1 = m_box1.getSize();

    sf::Vector2f pos2 = m_box2.getPosition();
    sf::Vector2f size2 = m_box2.getSize();

    pos1.x = std::clamp(pos1.x, 0.0f, width - size1.x);
    pos1.y = std::clamp(pos1.y, 0.0f, height - size1.y);

    pos2.x = std::clamp(pos2.x, 0.0f, width - size2.x);
    pos2.y = std::clamp(pos2.y, 0.0f, height - size2.y);

    m_box1.setPosition(pos1);
    m_box2.setPosition(pos2);


   /* positionBox1.x = std::clamp(positionBox1.x, 0.0f, width - sizeBox1.x);
    positionBox1.y = std::clamp(positionBox1.y, 0.0f, height - sizeBox1.y);

    positionBox2.x = std::clamp(positionBox2.x, 0.0f, width - sizeBox2.x);
    positionBox2.y = std::clamp(positionBox2.y, 0.0f, height - sizeBox2.y);*/


    
    //m_box1.setPosition(positionBox1);
    //m_box2.setPosition(positionBox2);

}

void Engine::render()
{
    m_window.clear(sf::Color::Black);

    m_box1.draw(m_window);
    m_box2.draw(m_window);

    m_window.display(); // Çizilenleri ekrana yansıt
}