#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <string>
#include <unordered_map>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	bool load(const std::string& id, const std::string& filePath);
	sf::Texture& get(const std::string&);

private:
	std::unordered_map<std::string, sf::Texture> m_textures;
};

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}