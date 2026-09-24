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

	OverlapData calculateOverlap(Entity& e1, Entity& e2) {
		OverlapData overlapData;

		if (!checkAABB(e1, e2)) return overlapData;

		sf::Vector2f pos1 = e1.getPosition();
		sf::Vector2f size1 = e1.getSize();
		sf::Vector2f pos2 = e2.getPosition();
		sf::Vector2f size2 = e2.getSize();

		overlapData.x = std::min(pos1.x + size1.x - pos2.x, pos2.x + size2.x - pos1.x);
		overlapData.y = std::min(pos1.y + size1.y - pos2.y, pos2.y + size2.y - pos1.y);

		overlapData.isHorizontal = overlapData.x < overlapData.y;
		overlapData.isColliding = true;

        return overlapData;
	}


    namespace {
        void resolvePosition(Entity& e1, Entity& e2, OverlapData& overlapData) {
            
            if (e1.body.isStatic && e2.body.isStatic) return;

            float ratio1 = 0.5f;
            float ratio2 = 0.5f;

            if (e1.body.isStatic || e2.body.isStatic)
            {
                if (e1.body.isStatic) {
                    ratio1 = 0.0f;
                    ratio2 = 1.0f;
                }
                else if (e2.body.isStatic) {
                    ratio1 = 1.0f;
                    ratio2 = 0.0f;
                }
            }

            sf::Vector2f pos1 = e1.getPosition();
            sf::Vector2f size1 = e1.getSize();
            sf::Vector2f pos2 = e2.getPosition();
            sf::Vector2f size2 = e2.getSize();


            if (overlapData.isHorizontal) {

                if (pos1.x < pos2.x) {

                    e1.setPosition(sf::Vector2f(pos1.x - overlapData.x * ratio1, pos1.y));
                    e2.setPosition(sf::Vector2f(pos2.x + overlapData.x * ratio2, pos2.y));
                }
                else {

                    e1.setPosition(sf::Vector2f(pos1.x + overlapData.x * ratio1, pos1.y));
                    e2.setPosition(sf::Vector2f(pos2.x - overlapData.x * ratio2, pos2.y));
                }
            }
            else {

                if (pos1.y < pos2.y) {

                    e1.setPosition(sf::Vector2f(pos1.x, pos1.y - overlapData.y * ratio1));
                    e2.setPosition(sf::Vector2f(pos2.x, pos2.y + overlapData.y * ratio2));
                }
                else {

                    e1.setPosition(sf::Vector2f(pos1.x, pos1.y + overlapData.y * ratio1));
                    e2.setPosition(sf::Vector2f(pos2.x, pos2.y - overlapData.y * ratio2));

                }
            }
        }

        void resolveVelocity(Entity& e1, Entity& e2, OverlapData& overlapData) {

            if (e1.body.isStatic && e2.body.isStatic) return;

            float& v1 = overlapData.isHorizontal ? e1.body.velocity.x : e1.body.velocity.y;
            float& v2 = overlapData.isHorizontal ? e2.body.velocity.x : e2.body.velocity.y;

            const float bounciness = 0.8f;

            if (e1.body.isStatic)
            {
				v2 = -v2 * bounciness;
                return;
            }

            if (e2.body.isStatic)
            {
                v1 = -v1 * bounciness;
                return;
            }

			float tempV1 = v1;
			v1 = v2 * bounciness;
			v2 = tempV1 * bounciness;
        }
    }

    void aabbCollisionHandle(Entity& entity1, Entity& entity2) {

		OverlapData overlapData = calculateOverlap(entity1, entity2);

        if (!overlapData.isColliding) return;

        resolvePosition(entity1, entity2, overlapData);

		resolveVelocity(entity1, entity2, overlapData);
    }

}