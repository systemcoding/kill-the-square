#pragma once

#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureLoader
{
public:
    TextureLoader();

    SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& filepath);

    void renderTexture(SDL_Renderer* renderer, SDL_Texture* texture);

    ~TextureLoader();
private:
    SDL_Texture* m_Textures;

    std::map<std::string, SDL_Texture*> m_TextureMap;
};

class Sprite
{
public:
    Sprite();

    void renderSprite(int x, int y, int width, int height, std::string filepath, SDL_Renderer* renderer);

    ~Sprite();
private:
    SDL_Rect m_SrcRect, m_DestRect;
    SDL_Texture* m_GetTexture;

    TextureLoader* m_TextureLoader{new TextureLoader()};

    std::string filepath;
};