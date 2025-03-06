#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "../utils/AudioManager.hpp"
#include <iostream>

class Player
{
private:
    sf::Sprite sprite;
    std::vector<sf::Texture> texturesRun, texturesJump;
    AudioManager &audioManager;

    int frameIndex;
    bool isJumping;
    float frameTime;
    sf::Clock clock;

    float velocityY;
    const float gravity;
    const float jumpForce;
    float groundY;

public:
    Player(const std::string &runPath, const std::string &jumpPath, const std::string &jumpSoundPath, sf::RenderWindow &window, AudioManager &audioMgr);

    void loadTextures(const std::string &path, std::vector<sf::Texture> &textures);
    void jump();
    void update();
    void draw(sf::RenderWindow &window);
};

#endif