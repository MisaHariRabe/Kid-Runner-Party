#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "SFML/Graphics.hpp"
#include <iostream>

class Background
{
private:
    sf::Texture texture;
    sf::Sprite sprite1, sprite2;
    float speed;

public:
    Background(const std::string &imagePath, sf::RenderWindow &window, float scrollSpeed);

    void update();
    void draw(sf::RenderWindow &window);
};

#endif