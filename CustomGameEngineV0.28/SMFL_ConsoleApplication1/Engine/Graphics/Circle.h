#pragma once
#include "Entity.h"

class Circle : public Entity
{
public:

	Circle(sf::Vector2f position = { 0.0f, 0.0f }, float radius = 16.0f)
		:Entity(position, { radius * 2, radius * 2 }, EntityType::Circle) {

		m_shape.setPosition(position);
		m_shape.setRadius(radius);
		m_shape.setFillColor(m_color);

	}

	void update(float dt) override {
		m_position += body.velocity * dt;
		m_shape.setPosition(m_position);
	}

	void draw(sf::RenderWindow& window) override {
		window.draw(m_shape);
	}

	void setColor(const sf::Color& color) { m_color = color; m_shape.setFillColor(color); }
	void setSpeed(float speed) { m_speed = speed; }
	float getSpeed() const { return m_speed; }

	void setJumpForce(float jumpForce) { m_jumpForce = jumpForce; }
	float getJumpForce() const { return m_jumpForce; }

	void updateShapePosition() { m_shape.setPosition(getPosition()); }

	sf::CircleShape& getShape() { return m_shape; }


private:
	sf::CircleShape m_shape;

	float m_jumpForce = 100.0f;
	float m_speed = 100.0f;

	sf::Vector2f m_direction{ 0.0f, 0.0f };

	bool m_isGrounded = false;

	sf::Color m_color = sf::Color::White;
};