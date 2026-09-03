#include "../Graphics/Entity.h"
#include "../Core/MathUtils.h"



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
	
	//body.velocity.y += GRAVITY * body.gravityScale * dt;

	m_shape.move(body.velocity * dt);

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


