#pragma once
#include "Object.h"


class bird:public Object
{
private:
public:
	void render(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect srcRect, SDL_Rect dstRect);
};

