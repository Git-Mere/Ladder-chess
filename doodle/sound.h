// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#pragma once
#include <SFML/Audio.hpp>

class Sound {
private:
    std::vector<sf::SoundBuffer> SoundBuffers{};
    std::vector<sf::Sound>       Sounds{};
public:
    void LoadSound(const std::string& file_path);
    void PlaySound(int i);
    void Setup();
};