#pragma once
#include "Object.h"
class background:public Object
{
public:
	void render(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect srcRect, SDL_Rect dstRect);
	void render(SDL_Renderer* ren, SDL_Texture* tex);
};

