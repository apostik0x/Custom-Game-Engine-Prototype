#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "../Graphics/Entity.h"

class Entity;

namespace Physics {

	bool checkAABB(Entity& entity1, Entity& entity2);
	void aabbCollisionHandle(Entity& entity1, Entity& entity2);
}