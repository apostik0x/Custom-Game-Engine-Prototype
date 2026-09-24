#include "Application.h"
#include <iostream>
#include <algorithm>
#include "MathUtils.h"
#include "../Physics/Physics.h"
#include "InputManager.h"

#include "../Graphics/Rectangle.h"
#include "../Graphics/Circle.h"

float width = 980 , height = 540 ;

Engine::Engine()
    : m_window(sf::VideoMode({ static_cast<unsigned int>(width), static_cast<unsigned int>(height) }), "Scence1")
{
    m_camera.setSize({ width, height });

    auto playerBox = std::make_unique<Rectangle>(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 50.0f));
    playerBox->body.isStatic = false;
    playerBox->setControllable(true); // Klavyeyle kontrol edilsin
    playerBox->setColor(sf::Color::Red); // Kırmızı renk
    m_entities.push_back(std::move(playerBox));

    auto Box = std::make_unique<Rectangle>(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(50.0f, 50.0f));
    Box->body.isStatic = false;
    Box->setColor(sf::Color::Yellow); // Sarı renk
    m_entities.push_back(std::move(Box));

    auto circle = std::make_unique<Circle>(sf::Vector2f(200.0f, 200.0f), 25.0f);
    circle->body.isStatic = false;
    circle->setColor(sf::Color::Blue); // Mavi renk
    m_entities.push_back(std::move(circle));


	


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

    if (!m_entities.empty()) {
        sf::Vector2f dir = m_input.getKeyboardInput();

        for (auto& entity : m_entities)
        {
            if (!entity->isControllable()) continue;

            if (dir != sf::Vector2f(0.0f, 0.0f))
            {
                entity->setVelocity(dir * 200.0f);

            }
            else
            {
                entity->setVelocity(sf::Vector2f(0.0f, 0.0f));
            }
        }
    };

    for (auto& entity : m_entities) {
        entity->update(dt);
    }

	// Çarpışma kontrolü ve çözümü
    for (size_t i = 0; i < m_entities.size(); i++)
    {
        for (size_t j = i + 1; j < m_entities.size(); j++)
        {
            Physics::aabbCollisionHandle(*m_entities[i], *m_entities[j]);
        }
    }
    
	// Sınırları kontrol et ve düzelt
    for (auto& entity : m_entities)
    {
        if (entity->body.isStatic) continue;

        sf::Vector2f pos = entity->getPosition();
        sf::Vector2f size = entity->getSize();
		sf::Vector2f vel = entity->getVelocity();

        if (pos.x <= 0.0f || pos.x >= width - size.x)
        {
            vel.x *= -0.8f;
        }

        if (pos.y <= 0.0f || pos.y >= height - size.y)
        {
            vel.y *= -0.8f;
        }

		pos.x = std::clamp(pos.x, 0.0f, width - size.x);
        pos.y = std::clamp(pos.y, 0.0f, height - size.y);

		entity->setVelocity(vel);
		entity->setPosition(pos);
    }

}

void Engine::render()
{
    m_window.clear(sf::Color::Black);

    for (auto& entity : m_entities)
    {
        entity->draw(m_window);
    }

    m_window.display(); // Çizilenleri ekrana yansıt
}