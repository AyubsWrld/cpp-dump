#pragma once 
#include <print>

namespace LO 
{
    struct Minigame 
    {
        void Speak() const; 
    };

    inline void Minigame::Speak() const { std::println("Hello"); }
}
