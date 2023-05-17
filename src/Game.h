#pragma once

<<<<<<< HEAD
#include "SDL.h"
=======
#include <SDL2/SDL.h>
>>>>>>> 4d8838975dd9ca5a0b4a67cba1f325f7e833bfb5

#include <string>
#include <memory>

#include "Window.h"
#include "World.h"
#include "Character.h"

class Game
{
private:
    std::unique_ptr<GameWindow> m_GameWindow;
    std::unique_ptr<World> m_World{new World()};
    std::unique_ptr<Character> m_Character{new Character()};

private:
    bool m_GameRunning;

public:
    void gameLoop();
    Game(std::string title, uint32_t width, uint32_t height);
    ~Game();

private:
    void createEntities();
    void render();
    void update(float dt);
    void clearScreen();
    void displayScreen();
    void handleEvents(float dt);
};