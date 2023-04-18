#pragma once
#include "Object.h"
class gameOver :public Object
{
public:
	void render(SDL_Renderer* ren);
private:
	SDL_Rect src, dst;
	int WIDTH = 375, HEIGHT = 313;
};

