#include "textureManager.h"

SDL_Texture* textureManager::loadTexture(const char* filepath, SDL_Renderer* ren)
{
    SDL_Texture* texture = IMG_LoadTexture(ren, filepath);
    return texture;
}
