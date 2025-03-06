#include "Player.hpp"
#include "../utils/TextureLoader.hpp"

Player::Player(const std::string &runPath, const std::string &jumpPath, const std::string &jumpSoundPath, sf::RenderWindow &window, AudioManager &audioMgr)
    : audioManager(audioMgr), frameIndex(0), isJumping(false), frameTime(0.04f), velocityY(0), gravity(0.8f), jumpForce(-10.0f)
{
    if (!TextureLoader::loadTextures(runPath, ").png", texturesRun) || !TextureLoader::loadTextures(jumpPath, ").png", texturesJump))
    {
        std::cerr << "Erreur : textures non chargées !" << std::endl;
        exit(-1);
    }

    sprite.setTexture(texturesRun[0]);

    float spriteScale = 0.8;
    sprite.setScale(spriteScale, spriteScale);
    groundY = window.getSize().y - sprite.getGlobalBounds().height;
    sprite.setPosition(10, groundY);

    audioManager.loadSound("jump", jumpSoundPath);
}

void Player::jump()
{
    if (!isJumping)
    {
        isJumping = true;
        velocityY = jumpForce;
        frameIndex = 0;
        audioManager.playSound("jump");
    }
}

void Player::update()
{
    if (clock.getElapsedTime().asSeconds() > frameTime)
    {
        if (isJumping)
        {
            velocityY += gravity;
            sprite.move(0, velocityY);

            if (sprite.getPosition().y >= groundY)
            {
                sprite.setPosition(sprite.getPosition().x, groundY);
                isJumping = false;
                frameIndex = 0;
            }
            else if (frameIndex < texturesJump.size() - 1)
            {
                frameIndex++;
            }
            sprite.setTexture(texturesJump[frameIndex]);
        }
        else
        {
            sprite.setTexture(texturesRun[frameIndex++ % texturesRun.size()]);
        }
        clock.restart();
    }
}

void Player::draw(sf::RenderWindow &window) { window.draw(sprite); }