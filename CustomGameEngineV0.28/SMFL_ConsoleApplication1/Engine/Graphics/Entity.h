#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

enum class EntityType
{
	Rectangle,
	Circle,
	// Add more entity types as needed
};

struct Material
{
	float restitution = 0.0f;
	float friction = 0.0f;
};

struct rigidbody2D
{
	sf::Vector2f velocity{ 0.0f, 0.0f };

	float gravityScale = 1.0f;
	float mass = 1.0f;

	bool useGravity = true;
	bool isStatic = false;

	Material material;
};

class Entity
{
public:
	Entity(
		const sf::Vector2f& entityPosition,
		const sf::Vector2f& entitySize
	);
	virtual ~Entity() = default;

	virtual void update(float dt) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	sf::Vector2f getPosition() const { return m_position; }
	sf::Vector2f getSize() const { return m_size; }
	sf::Vector2f getVelocity() const { return body.velocity; }

	bool isControllable() const { return m_isControllable; }
	void setControllable(bool controllable) { m_isControllable = controllable; }

	void setPosition(sf::Vector2f pos) { m_position = pos; }
	void setVelocity(sf::Vector2f vel) { body.velocity = vel; }

	rigidbody2D body;

protected:

	bool m_isControllable = false;
	sf::Vector2f m_position;
	sf::Vector2f m_size;

};
