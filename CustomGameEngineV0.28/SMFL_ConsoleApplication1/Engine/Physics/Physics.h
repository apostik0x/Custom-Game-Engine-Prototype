#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "../Graphics/Entity.h"

class Entity;

struct OverlapData {
    bool isColliding = false;
    float x = 0.0f;
    float y = 0.0f;
    bool isHorizontal = false;
};
namespace Physics {

	bool checkAABB(Entity& entity1, Entity& entity2);
	void aabbCollisionHandle(Entity& entity1, Entity& entity2);
}