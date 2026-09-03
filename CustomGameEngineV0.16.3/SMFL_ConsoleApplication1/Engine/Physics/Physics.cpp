#include "Physics.h"
#include "../Graphics/Entity.h"
#include <algorithm>


namespace Physics {

	bool checkAABB(Entity& entity1, Entity& entity2) {
		return (entity1.getPosition().x < entity2.getPosition().x + entity2.getSize().x &&
			entity1.getPosition().x + entity1.getSize().x > entity2.getPosition().x &&
			entity1.getPosition().y < entity2.getPosition().y + entity2.getSize().y &&
			entity1.getPosition().y + entity1.getSize().y > entity2.getPosition().y);
	}

	void aabbCollisionHandle(Entity& entity1, Entity& entity2) {
		if (checkAABB(entity1, entity2)) {
			sf::Vector2f pos1 = entity1.getPosition();
			sf::Vector2f size1 = entity1.getSize();
			sf::Vector2f pos2 = entity2.getPosition();
			sf::Vector2f size2 = entity2.getSize();
			float overlapX = std::min(pos1.x + size1.x - pos2.x, pos2.x + size2.x - pos1.x);
			float overlapY = std::min(pos1.y + size1.y - pos2.y, pos2.y + size2.y - pos1.y);
			if (overlapX < overlapY) {
				if (pos1.x < pos2.x) {
					entity1.setPosition(sf::Vector2f(pos1.x - overlapX, pos1.y));
				}
				else {
					entity1.setPosition(sf::Vector2f(pos1.x + overlapX, pos1.y));
				}
				entity1.body.velocity.x = 0.0f;
			}
			else {
				if (pos1.y < pos2.y) {
					entity1.setPosition(sf::Vector2f(pos1.x, pos1.y - overlapY));
				}
				else {
					entity1.setPosition(sf::Vector2f(pos1.x, pos1.y + overlapY));
				}
				entity1.body.velocity.y = 0.0f;
			}
		}
	}

}


/*return(entity1.getPosition().x < entity2.getPosition().x + entity2.getSize().x &&
			entity1.getPosition().x + entity1.getSize().x > entity2.getPosition().x &&
			entity1.getPosition().y < entity2.getPosition().y + entity2.getSize().y &&
			entity1.getPosition().y + entity1.getSize().y > entity2.getPosition().y);*/

/*void Physics::aabbCollisionHandle(Entity& entity1, Entity& entity2) {
    if (Physics::checkAABB(entity1, entity2))
    {
        float overlapLeft = (entity1.getPosition().x + entity1.getSize().x) - entity2.getPosition().x;
        float overlapRight = (entity2.getPosition().x + entity2.getSize().x) - entity1.getPosition().x;
        float overlapTop = (entity1.getPosition().y + entity1.getSize().y) - entity2.getPosition().y;
        float overlapBot = (entity2.getPosition().y + entity2.getSize().y) - entity1.getPosition().y;

        float minX = std::min(overlapLeft, overlapRight);
        float minY = std::min(overlapTop, overlapBot);
        if (minX < minY)
        {
            if (overlapLeft < overlapRight)
            {
                //soldan çarptı
                entity1.setVelocity({ -100.0f, 0.0f });
                entity2.setVelocity({ 100.0f, 0.0f });

                entity1.setPosition({ entity1.getPosition().x - overlapLeft, entity1.getPosition().y });
                entity2.setPosition({ entity2.getPosition().x + overlapLeft, entity2.getPosition().y });
            }
            else
            {
                //sağdan çarptı
                entity1.setVelocity({ 100.0f, 0.0f });
                entity2.setVelocity({ -100.0f, 0.0f });

                entity1.setPosition({ entity1.getPosition().x + overlapRight, entity1.getPosition().y });
                entity2.setPosition({ entity2.getPosition().x - overlapRight, entity2.getPosition().y });
            }
        }
        else
        {
            if (overlapTop < overlapBot)
            {
                //üstten çarptı
                entity1.setVelocity({ entity1.getVelocity().x, 0.0f });
                entity2.setVelocity({ entity2.getVelocity().x, 100.0f });

                entity1.setPosition({ entity1.getPosition().x , entity1.getPosition().y - overlapTop });
                entity2.setPosition({ entity2.getPosition().x , entity2.getPosition().y + overlapTop });
            }
            else
            {
                //alttan çarptı
                entity1.setVelocity({ entity1.getVelocity().x, 0.0f });
                entity2.setVelocity({ entity2.getVelocity().x, -100.0f });

                entity1.setPosition({ entity1.getPosition().x, entity1.getPosition().y + overlapBot });
                entity2.setPosition({ entity2.getPosition().x, entity2.getPosition().y - overlapBot });
            }
        }
    }
}*/