#pragma once
#include "Object.h"
#include <ctime>
#include <cstdlib>
class pipe:public Object
{
private:
	SDL_Rect src, dst;
	double yPos = 0;
	SDL_Rect box1, box2;
public:
	void render(SDL_Renderer* ren);
	void ranYPos();
	SDL_Rect getBox1() { return box1; }
	SDL_Rect getBox2() { return box2; }
	void renderDie(SDL_Renderer* ren);
};

