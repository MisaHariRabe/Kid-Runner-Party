#include "Game.hpp"

Game::Game()
    : window(sf::VideoMode(1280, 720), "SFML Animation"),
      audioManager(),
      player("assets/images/characters/character1/Run", "assets/images/characters/character1/Jump", "assets/sounds/SoundFX/happyJump.ogg", window, audioManager),
      background("assets/images/background/background1.png", window, 1.0f),
      star("assets/images/misc/star/", window)
{
    audioManager.loadMusic("background", "assets/sounds/BGM/music1.ogg");
    audioManager.playMusic("background", true);
}

void Game::run()
{
    while (window.isOpen())
    {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            player.jump();
    }
}

void Game::update()
{
    background.update();
    player.update();
    star.update();
}

void Game::render()
{
    window.clear();
    background.draw(window);
    player.draw(window);
    star.draw(window);
    window.display();
}