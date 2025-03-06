#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../entities/Player.hpp"
#include "../entities/Background.hpp"
#include "../entities/Collectible.hpp"
#include <iostream>
#include <vector>

class Game
{
private:
    sf::RenderWindow window;
    AudioManager audioManager;
    Player player;
    Background background;
    Collectible star;

public:
    Game();

    void run();
    void handleEvents();
    void update();
    void render();
};

#endif