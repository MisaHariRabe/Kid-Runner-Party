#include "Collectible.hpp"

Collectible::Collectible(const std::string &path, sf::RenderWindow &window)
    : frameIndex(0), frameTime(0.04f)
{
    loadTextures(path, textures);

    if (textures.empty())
    {
        std::cerr << "Erreur : textures étoiles non chargées !" << std::endl;
        exit(-1);
    }

    sprite.setTexture(textures[0]);
    sprite.scale(sf::Vector2f(0.5f, 0.5f));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
}

void Collectible::loadTextures(const std::string &path, std::vector<sf::Texture> &textures)
{
    for (int i = 1; i <= 10; i++)
    {
        sf::Texture texture;
        std::string filePath = path + std::to_string(i) + ".png";
        if (!texture.loadFromFile(filePath))
        {
            std::cerr << "Attention : image non trouvée -> " << filePath << std::endl;
            continue;
        }

        textures.push_back(texture);
    }
}

void Collectible::update()
{
    if (clock.getElapsedTime().asSeconds() > frameTime)
    {
        sprite.setTexture(textures[frameIndex++ % textures.size()]);
        clock.restart();
    }
}

void Collectible::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}