#include "Background.hpp"

Background::Background(const std::string &imagePath, sf::RenderWindow &window, float scrollSpeed)
    : speed(scrollSpeed)
{
    if (!texture.loadFromFile(imagePath))
    {
        std::cerr << "Erreur : impossible de charger le background !" << std::endl;
        exit(-1);
    }

    sprite1.setTexture(texture);
    sprite2.setTexture(texture);

    float scaleX = static_cast<float>(window.getSize().x) / texture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / texture.getSize().y;

    sprite1.setScale(scaleX, scaleY);
    sprite2.setScale(scaleX, scaleY);

    sprite1.setPosition(0, 0);
    sprite2.setPosition(sprite1.getGlobalBounds().width, 0);
}

void Background::update()
{
    sprite1.move(-speed, 0);
    sprite2.move(-speed, 0);

    if (sprite1.getPosition().x + sprite1.getGlobalBounds().width <= 0)
    {
        sprite1.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, 0);
    }

    if (sprite2.getPosition().x + sprite2.getGlobalBounds().width <= 0)
    {
        sprite2.setPosition(sprite1.getPosition().x + sprite1.getGlobalBounds().width, 0);
    }
}

void Background::draw(sf::RenderWindow &window)
{
    window.draw(sprite1);
    window.draw(sprite2);
}