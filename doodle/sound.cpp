// Name              : Seungheon Jeon, Sangbeom Kim, Sehun Kim
// Assignment Name   : Game Prototype 1
// Course            : CS120
// Term & Year       : fall/2020

#include "sound.h"
#include "doodle/doodle.hpp"
#include <iostream>

using namespace doodle;

[[noreturn]] void error(const std::string& s) { throw std::runtime_error(s); }

void Sound::Setup() {
    LoadSound("assets/tile.ogg");
    LoadSound("assets/digipen.ogg");
    LoadSound("assets/intro2.ogg");
    LoadSound("assets/main.ogg");
    LoadSound("assets/ingame.ogg");
    LoadSound("assets/button.ogg");
    LoadSound("assets/win.ogg");
}

void Sound::LoadSound(const std::string& file_path)
{
    SoundBuffers.emplace_back();
    sf::SoundBuffer& buffer = SoundBuffers.back();
    if (!buffer.loadFromFile(file_path))
    {
        error("Failed to load " + file_path);
    }
}

void Sound::PlaySound(int i)
{
    int buffer_index = i;
    for (auto& sound : Sounds)
    {
        if (sound.getStatus() != sf::SoundSource::Playing)
        {
            sound.setBuffer(SoundBuffers[buffer_index]);
            sound.play();
            return;
        }
    }
    Sounds.emplace_back(SoundBuffers[buffer_index]);
    Sounds.back().play();
}