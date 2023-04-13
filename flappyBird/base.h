#pragma once
#include "Object.h"
class base:public Object
{
private:
	SDL_Rect src, dst;
public:
	void render(SDL_Renderer* ren);
	void renderDie(SDL_Renderer* ren);
};

