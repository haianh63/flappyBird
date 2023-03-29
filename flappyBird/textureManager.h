#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
class textureManager
{
public:
	static SDL_Texture* loadTexture(const char* filepath, SDL_Renderer* ren);
};

