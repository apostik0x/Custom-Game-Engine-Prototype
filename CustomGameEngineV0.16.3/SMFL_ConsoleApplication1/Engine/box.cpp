/*#include "../Engine/Graphics/Entity.h"
#include "../Engine/Core/MathUtils.h"



Entity::Entity(
	sf::Vector2f entityPosition,
	sf::Vector2f entityDirection,
	sf::Vector2f entitySize,
	bool entityControllable
) :
	m_position(entityPosition),
	m_direction(entityDirection),
	m_size(entitySize),
	m_isControllable(entityControllable)

{
	m_shape.setSize(m_size);
	m_shape.setFillColor(m_color);
	m_shape.setPosition(m_position);
	
	
}

Entity::~Entity() {}

void Entity::update(float dt) {

	float moveDirectionX{ 0.0f };
	float moveDirectionY{ 0.0f };
	float GRAVITY = 9.81f * 100.0f;

	if (m_isControllable)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))moveDirectionY -= 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) moveDirectionY += 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) moveDirectionX -= 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) moveDirectionX += 1.0f;

		

		if (m_isGrounded)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				body.velocity.y = -m_jumpForce;
				m_isGrounded = false;
			}
		}

		body.velocity.x = moveDirectionX * m_speed;
		body.velocity.y = moveDirectionY * m_speed;
	}
	//body.velocity.y += GRAVITY * body.gravityScale * dt;
		

	m_shape.move(body.velocity * dt );

	float screenBottom = 540.0f;
	if (m_shape.getPosition().y >= screenBottom - m_shape.getSize().y)
	{
		sf::Vector2f pos = m_shape.getPosition();
		pos.y = screenBottom - m_shape.getSize().y; // Yere sabitle
		m_shape.setPosition(pos);

		body.velocity.y = 0.0f; // Yerçekiminin birikmesini engelle
		m_isGrounded = true; // Yere bastığı için tekrar zıplama izni ver
	}

	m_position = m_shape.getPosition();
	
	
}

void Entity::draw(sf::RenderWindow& window) {

	window.draw(m_shape);
}

sf::Vector2f Entity::getPosition() const
{

	return m_shape.getPosition();
}

sf::Vector2f Entity::getSize() const
{
	return m_shape.getSize();
}

sf::Vector2f Entity::getVelocity() const
{
	return body.velocity;
}

void Entity::setPosition(sf::Vector2f position)
{
	m_shape.setPosition(position);
}

void Entity::setVelocity(sf::Vector2f velocity) {
	body.velocity = velocity;
}


*/