#pragma once
#include "Object.h"
#include <ctime>
#include <cstdlib>
class pipe:public Object
{
private:
	SDL_Rect src, dst;
	double yPos = 0;
public:
	void render(SDL_Renderer* ren);
	void ranYPos();
};

