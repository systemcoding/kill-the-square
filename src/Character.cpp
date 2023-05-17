#include "Character.h"

//////////////////////////////////// Character class implementation ////////////////////////////////////////////

Character::Character()
{
    m_PlayerPositions.x = 400.0f;
    m_PlayerPositions.y = 100.0f;
    m_PlayerVelocity.x = 1200.0f;
    m_PlayerVelocity.y = 1200.0f;
    m_PlayerAcc.x = 350.0f;
    m_PlayerAcc.y = 1000.0f;
}

bool Character::handleCollision(SDL_Rect rectA, SDL_Rect rectB)
{
    // For Rectangle A
    int rightA, leftA, topA, bottomA;
    // For rectangle B
    int rightB, leftB, topB, bottomB;

    // Calculate sides of rectangle A
    rightA = rectA.x + rectA.w;
    leftA = rectA.x;
    topA = rectA.y;
    bottomA = rectA.y + rectA.h;

    // Calculate sides of rectangle B
    rightB = rectB.x + rectB.w;
    leftB = rectB.x;
    topB = rectB.y;
    bottomB = rectB.y + rectB.h;

    /* If the sides are outside of the other box, the collision is false */
    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    // If none of the sides from A are outside B
    return true;
}

void Character::createPlayer()
{
    m_PlayerRect = {(int)m_PlayerPositions.x, (int)m_PlayerPositions.y, PLAYER_WIDTH, PLAYER_HEIGHT};
}

void Character::createEnemy()
{
    for (int i = 0; i < 3; i++)
    {
        m_Enemies.emplace_back(SDL_Rect{(int)m_EnemyPositions.x, (int)m_EnemyPositions.y, ENEMY_WIDTH, ENEMY_HEIGHT});
        m_EnemyPositions.x += ENEMY_WIDTH + 70.0f;
    }
}

void Character::renderPlayer(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 39, 81, 187, 255);
    SDL_RenderFillRect(renderer, &m_PlayerRect);
}

void Character::renderEnemy(SDL_Renderer *renderer)
{
    for (int i = 0; i < m_Enemies.size(); i++)
    {
        SDL_SetRenderDrawColor(renderer, 232, 0, 0, 0.8);
        SDL_RenderFillRect(renderer, &m_Enemies[i]);
    }
}

void Character::handlePlayerEvents(float dt)
{
    SDL_Event event;

    m_PlayerVelocity.x = 0.0f;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_A:
                m_PlayerVelocity.x -= m_PlayerAcc.x;
                break;
            case SDL_SCANCODE_D:
                m_PlayerVelocity.x += m_PlayerAcc.x;
                break;
            case SDL_SCANCODE_SPACE:
                m_PlayerVelocity.y = -m_PlayerAcc.y;
            }
        }
    }
}

void Character::update(float dt, SDL_Renderer *renderer)
{

    /*
        The jittery stuff might be due to you converting from a float during collision with the ground. In some 2d
        sidescrollers developers do what's called a ground check where they disable collision while the character is
        on the ground and enable it when the character is jumping/falling etc.
        While the character is on the ground they set the Y location to the same as the ground.
    */

    // Gravity
    m_PlayerVelocity.y += GRAVITY;

    // Update positions
    m_PlayerPositions.x += m_PlayerVelocity.x * dt;
    m_PlayerPositions.y += m_PlayerVelocity.y * dt;

    // Collision detection
    if (SDL_HasIntersection(&m_PlayerRect, &globals::m_BottomRect))
    {
        m_PlayerPositions.y = globals::m_BottomRect.y - PLAYER_HEIGHT;
        m_IsInAir = false;
        m_PlayerVelocity.y = 0.0f;
    }

    int score = 0;
    for (auto &enemy : m_Enemies)
    {
        if (handleCollision(m_PlayerRect, enemy))
        {
            enemy = {0, 0, 0, 0};
            score++;
        }
    }

    // Set Character Rectangle positions
    m_PlayerRect.x = (int)m_PlayerPositions.x;
    m_PlayerRect.y = (int)m_PlayerPositions.y;
}

void Character::updateEnemy(float dt)
{
    m_EnemyVelocity.y += GRAVITY;
    // Update positions
    // m_EnemyPosition.x += m_EnemyVelocity.x * 0.003;
    m_EnemyPositions.y += m_EnemyVelocity.y * 0.003;

    if (m_EnemyPositions.y + ENEMY_HEIGHT >= 600)
    {
        m_EnemyPositions.y = 600 - ENEMY_HEIGHT;
        m_EnemyVelocity.y = 0;
    }

    for (int i = 0; i < m_Enemies.size(); i++)
    {
        if (SDL_HasIntersection(&m_Enemies[i], &globals::m_BottomRect))
        {
            m_EnemyPositions.y = globals::m_BottomRect.y - ENEMY_HEIGHT;
            m_EnemyVelocity.y = 0.0f;
        }

        m_Enemies[i].y = (int)m_EnemyPositions.y;
    }
}

Character::~Character()
{
}
