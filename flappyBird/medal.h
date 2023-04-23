#pragma once
#include "Object.h"
class medal:public Object
{
public:
	void render(SDL_Renderer* ren, int x, int y);
private:
	SDL_Rect dst;
	int WIDTH =66 , HEIGHT =66 ;
};

