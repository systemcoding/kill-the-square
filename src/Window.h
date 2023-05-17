#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "utils/Log.h"

using namespace utils;

class GameWindow
{
private:
    static SDL_Window *m_Window;
    static SDL_Renderer *m_Renderer;

private:
    std::string m_Title;
    uint32_t m_Width;
    uint32_t m_Height;

public:
    GameWindow(std::string title, uint32_t width, uint32_t height);

    static void createWindow(std::string title, uint32_t width, uint32_t height);

    SDL_Renderer *getRendererInstance() { return m_Renderer; }
    SDL_Window *getWindowInstance() { return m_Window; }

    ~GameWindow();
};