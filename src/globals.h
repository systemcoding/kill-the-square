#pragma once

#include <SDL2/SDL.h>

namespace globals
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    static SDL_Rect m_BottomRect = {
        SCREEN_WIDTH / 2 - 400, 500, SCREEN_WIDTH, 100};
};