#include "AudioManager.hpp"

AudioManager::AudioManager() : soundVolume(80.f), musicVolume(100.f) {}

AudioManager::~AudioManager() {}

bool AudioManager::loadSound(const std::string &name, const std::string &filename)
{
    if (soundBuffers.find(name) != soundBuffers.end())
    {
        return true;
    }

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filename))
    {
        std::cerr << "Erreur lors du chargement du fichier sonore : " << filename << std::endl;
        return false;
    }
    soundBuffers[name] = std::move(buffer);
    return true;
}

bool AudioManager::loadMusic(const std::string &name, const std::string &filename)
{
    if (music.find(name) != music.end())
    {
        return true;
    }

    auto newMusic = std::make_unique<sf::Music>();
    if (!newMusic->openFromFile(filename))
    {
        std::cerr << "Erreur lors du chargement de la musique : " << filename << std::endl;
        return false;
    }
    music[name] = std::move(newMusic);
    return true;
}

void AudioManager::playSound(const std::string &name, bool loop)
{
    if (soundBuffers.find(name) != soundBuffers.end())
    {
        auto sound = std::make_unique<sf::Sound>();
        sound->setBuffer(soundBuffers[name]);
        sound->setLoop(loop);
        sound->setVolume(soundVolume);
        sounds[name] = std::move(sound);
        sounds[name]->play();
    }
    else
    {
        std::cerr << "Son non trouvé : " << name << std::endl;
    }
}

void AudioManager::playMusic(const std::string &name, bool loop)
{
    if (music.find(name) != music.end())
    {
        music[name]->setLoop(loop);
        music[name]->setVolume(musicVolume);
        music[name]->play();
    }
    else
    {
        std::cerr << "Musique non trouvée : " << name << std::endl;
    }
}

void AudioManager::stopSound(const std::string &name)
{
    if (sounds.find(name) != sounds.end())
    {
        sounds[name]->stop();
    }
}

void AudioManager::stopMusic()
{
    for (auto &pair : music)
    {
        pair.second->stop();
    }
}

void AudioManager::setSoundVolume(float volume)
{
    soundVolume = volume;
    for (auto &pair : sounds)
    {
        pair.second->setVolume(volume);
    }
}

void AudioManager::setMusicVolume(float volume)
{
    musicVolume = volume;
    for (auto &pair : music)
    {
        pair.second->setVolume(volume);
    }
}
