#include "World.h"

World::World()
{

}

void World::createPlatformRect(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &globals::m_BottomRect);
}

World::~World()
{
}