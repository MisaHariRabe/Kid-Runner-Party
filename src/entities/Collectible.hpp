#include <SFML/Graphics.hpp>
#include <iostream>

class Collectible
{
private:
    sf::Sprite sprite;
    std::vector<sf::Texture> textures;

    int frameIndex;
    float frameTime;
    sf::Clock clock;

public:
    Collectible(const std::string &path, sf::RenderWindow &window);

    void loadTextures(const std::string &path, std::vector<sf::Texture> &textures);
    void update();
    void draw(sf::RenderWindow &window);
};