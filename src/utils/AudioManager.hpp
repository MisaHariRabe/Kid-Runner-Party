#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <map>
#include <memory>

class AudioManager
{
public:
    AudioManager();
    ~AudioManager();

    bool loadSound(const std::string &name, const std::string &filename);
    bool loadMusic(const std::string &name, const std::string &filename);

    void playSound(const std::string &name, bool loop = false);
    void playMusic(const std::string &name, bool loop = true);

    void stopSound(const std::string &name);
    void stopMusic();

    void setSoundVolume(float volume);
    void setMusicVolume(float volume);

private:
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::map<std::string, std::unique_ptr<sf::Music>> music;
    std::map<std::string, sf::Sound> sounds;

    float soundVolume;
    float musicVolume;
};

#endif
