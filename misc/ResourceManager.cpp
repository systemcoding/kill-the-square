#include "ResourceManager.h"

// TextureLoader Implementation

TextureLoader::TextureLoader()
{
}

SDL_Texture* TextureLoader::loadTexture(SDL_Renderer* renderer, const std::string& filepath)
{
    // small caching like system to not repeat the generation of images every frame
    if(m_TextureMap.count(filepath) == 0)
    {
        m_TextureMap[filepath] = IMG_LoadTexture(renderer, filepath.c_str());
    }

    return m_TextureMap[filepath];
}

TextureLoader::~TextureLoader()
{
}

//////////////////////////////////////
// Sprite class implementation
//////////////////////////////////////

Sprite::Sprite()
{
}

void Sprite::renderSprite(int x, int y, int width, int height, std::string filepath, SDL_Renderer* renderer)
{
    m_SrcRect = { 0, 0, width, height };
    m_DestRect = { x, y, m_SrcRect.w, m_SrcRect.h };

    m_GetTexture = m_TextureLoader->loadTexture(renderer, filepath);

    SDL_RenderCopy(renderer, m_GetTexture, &m_SrcRect, &m_DestRect);
}

Sprite::~Sprite() 
{
    delete m_TextureLoader;
}