#pragma once

<<<<<<< HEAD
#include <SDL.h>
=======
#include <SDL2/SDL.h>
>>>>>>> 4d8838975dd9ca5a0b4a67cba1f325f7e833bfb5

#include "utils/Log.h"
#include "globals.h"

#include <memory>
#include <cmath>

using namespace utils;

class World
{
public:
    World();

    void createPlatformRect(SDL_Renderer* renderer);

    ~World();
};