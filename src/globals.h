#pragma once

<<<<<<< HEAD
#include <SDL.h>
=======
#include <SDL2/SDL.h>
>>>>>>> 4d8838975dd9ca5a0b4a67cba1f325f7e833bfb5

namespace globals
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    static SDL_Rect m_BottomRect = {
        SCREEN_WIDTH / 2 - 400, 500, SCREEN_WIDTH, 100};
};