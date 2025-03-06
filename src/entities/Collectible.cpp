#include "Collectible.hpp"
#include "../utils/TextureLoader.hpp"

Collectible::Collectible(const std::string &path, sf::RenderWindow &window)
    : frameIndex(0), frameTime(0.04f)
{
    if (!TextureLoader::loadTextures(path, ".png", textures))
    {
        std::cerr << "Erreur : textures étoiles non chargées !" << std::endl;
        exit(-1);
    }

    sprite.setTexture(textures[0]);
    sprite.scale(sf::Vector2f(0.5f, 0.5f));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
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