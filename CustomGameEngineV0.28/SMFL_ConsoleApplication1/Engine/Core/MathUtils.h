#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

namespace EngineMath {
	inline sf::Vector2f normalize(const sf::Vector2f& source)
	{
		float lenght = std::sqrt(source.x * source.x + source.y * source.y);
		if (lenght != 0.0f)
			return sf::Vector2f(source.x / lenght, source.y / lenght);
		return source;
	}

	inline bool checkAABB(sf::Vector2f box1Size, sf::Vector2f box1Pos, sf::Vector2f box2Size, sf::Vector2f box2Pos) {

		return( box1Pos.x < box2Pos.x + box2Size.x &&
				box1Pos.x + box1Size.x > box2Pos.x&&
				box1Pos.y < box2Pos.y + box2Size.y &&
				box1Pos.y + box1Size.y > box2Pos.y	);
	}
}