#include "Game.h"

Game::Game(std::string title, uint32_t width, uint32_t height)
    : m_GameRunning(true)
{
    GameWindow::createWindow(title, width, height);
}

void Game::gameLoop()
{
    float dt;
    const int FPS = 60;
    uint32_t frameStart;
    float previousTime = 0.0f;
    int frameTime;

    createEntities();
    while (m_GameRunning)
    {
        frameStart = SDL_GetTicks(); // Get the number of milliseconds since SDL library initialization.

        // Calculate delta time since the previous frame
        dt = (frameStart - previousTime) / 1000.0f;
        previousTime = frameStart;

        ///////////////////// Game related functions //////////////////////
        handleEvents(dt);
        clearScreen();
        update(dt);
        render();
        displayScreen();
        //////////////////////////////////////////////////////////////////

        // Limit the frame rate
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < 1000 / FPS)
        {
            SDL_Delay((1000 / FPS) - frameTime);
        }
    }
}

void Game::createEntities()
{
    m_Character->createPlayer();
    m_Character->createEnemy();
}

void Game::handleEvents(float dt)
{
    m_Character->handlePlayerEvents(dt);
}

void Game::clearScreen()
{
    SDL_SetRenderDrawColor(m_GameWindow->getRendererInstance(), 52, 52, 52, 255);
    SDL_RenderClear(m_GameWindow->getRendererInstance());
}

void Game::update(float dt)
{
    m_Character->update(dt, m_GameWindow->getRendererInstance());
    m_Character->updateEnemy(dt);
}

void Game::displayScreen()
{
    SDL_RenderPresent(m_GameWindow->getRendererInstance());
}

void Game::render()
{
    m_Character->renderPlayer(m_GameWindow->getRendererInstance());
    m_Character->renderEnemy(m_GameWindow->getRendererInstance());
    m_World->createPlatformRect(m_GameWindow->getRendererInstance());
}

Game::~Game()
{
}