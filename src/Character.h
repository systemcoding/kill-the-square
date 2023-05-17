#pragma once

#include <SDL2/SDL.h>

#include <memory>
#include <vector>

#include "utils/Vector2d.h"
#include "globals.h"
#include "utils/Log.h"

using namespace utils;

class Character
{
public:
    Character();

    bool handleCollision(SDL_Rect rectA, SDL_Rect rectB);

    void createPlayer();
    void createEnemy();

    void renderPlayer(SDL_Renderer *renderer);
    void renderEnemy(SDL_Renderer *renderer);

    void update(float dt, SDL_Renderer *renderer);
    void updateEnemy(float dt);

    void handlePlayerEvents(float dt);

    ~Character();

private:
    int PLAYER_SPEED = 1000;
    int PLAYER_WIDTH = 64, ENEMY_WIDTH = 64;
    int PLAYER_HEIGHT = 64, ENEMY_HEIGHT = 64;
    const int GRAVITY = 30;
    bool m_IsInAir{true};
    bool m_CollisionOccured{false};

private:
    SDL_Rect m_PlayerRect;
    std::vector<SDL_Rect> m_Enemies;

private:
    Vector2d m_PlayerPositions, m_EnemyPositions;
    Vector2d m_PlayerVelocity, m_EnemyVelocity;
    Vector2d m_PlayerAcc;
};
