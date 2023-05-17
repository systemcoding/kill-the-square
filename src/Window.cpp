/* This file contains the rendering loop and basic methods to create and run a window.
   No extra junk!

   Written By: System Coding a.k.a Revanth
   Date: 10-01-2023
*/

#include "Window.h"

SDL_Window *GameWindow::m_Window;
SDL_Renderer *GameWindow::m_Renderer;

GameWindow::GameWindow(std::string title, uint32_t width, uint32_t height)
    : m_Title(title), m_Width(width), m_Height(height)
{
}

void GameWindow::createWindow(std::string title, uint32_t width, uint32_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        Log::Error("SDL_INIT_VIDEO Failed", SDL_GetError(), "\n");
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        Log::Error("SDL_Image initialisation failed", SDL_GetError(), "\n");
    }

    m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, width, height, 0);

    if (m_Window == nullptr)
    {
        Log::Error("SDL_CreateWindow() function failed! ", SDL_GetError(), "\n");
        SDL_Quit();
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    if (m_Renderer == nullptr)
    {
        SDL_DestroyWindow(m_Window);
        Log::Error("SDL_CreateRenderer() function failed ", SDL_GetError(), "\n");
        SDL_Quit();
    }
}

GameWindow::~GameWindow()
{
    SDL_DestroyWindow(m_Window);
}
