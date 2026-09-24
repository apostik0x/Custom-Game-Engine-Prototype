#include "../Graphics/Entity.h"
#include "../Core/MathUtils.h"



Entity::Entity(
	const sf::Vector2f& entityPosition,
	const sf::Vector2f& entitySize
) : m_position(entityPosition), m_size(entitySize)

{

}

void Entity::update(float dt) {

}