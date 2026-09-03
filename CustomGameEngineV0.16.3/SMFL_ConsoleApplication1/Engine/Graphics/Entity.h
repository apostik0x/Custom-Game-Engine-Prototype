#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

struct rigidbody2D
{
	sf::Vector2f velocity{ 0.0f, 0.0f };
	float gravityScale = 1.0f;
	bool useGravity = true;
	bool isStatic = false;
};

class Entity
{
public:
	Entity(
		sf::Vector2f entityPosition,
		sf::Vector2f entityDireciton,
		sf::Vector2f entitySize,
		bool entityControllable
	);
	~Entity();

	//bool createEntity(const std::string& filePath);

	void update(float dt);
	void draw(sf::RenderWindow& window);

	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
	sf::Vector2f getVelocity() const;

	void setPosition(sf::Vector2f position);
	void setVelocity(sf::Vector2f velocity);
	void setControllable(bool entityControllable) { m_isControllable = entityControllable; }
	void setColor(sf::Color color) { m_color = color; m_shape.setFillColor(m_color); }
	void setSpeed(float speed) { m_speed = speed; }
	void setJumpForce(float jumpForce) { m_jumpForce = jumpForce; }

	rigidbody2D body;

private:

	//sf::Texture m_texture;
	//std::optional<sf::Sprite> m_sprite;

	sf::RectangleShape m_shape;

	sf::Vector2f m_position;
	sf::Vector2f m_direction;
	sf::Vector2f m_size;

	float m_jumpForce = 100.0f;
	float m_speed = 100.0f;
	
	bool m_isControllable;
	bool m_isGrounded = false;

	sf::Color m_color = sf::Color::White;
};
