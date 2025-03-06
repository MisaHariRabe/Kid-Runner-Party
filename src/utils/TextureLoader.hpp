#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

class TextureLoader
{
public:
    static bool loadTextures(const std::string &path, const std::string &extension, std::vector<sf::Texture> &textures, int textureCount = 15)
    {
        for (int i = 1; i <= textureCount; i++)
        {
            sf::Texture texture;
            std::string filePath = path + std::to_string(i) + extension;
            if (!texture.loadFromFile(filePath))
            {
                std::cerr << "Texture not found: " << filePath << std::endl;
                continue;
            }
            textures.push_back(texture);
        }
        return !textures.empty();
    }
};

#endif
