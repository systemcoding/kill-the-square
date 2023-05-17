#pragma once

#include <SDL2/SDL.h>

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