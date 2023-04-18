#pragma once
#include "Object.h"
class button :public Object
{
public:
	void render(SDL_Renderer* ren , int x,int y);
	void setWidthHeight(int w, int h) {
		WIDTH = w;
		HEIGHT = h;
	}
private:
	SDL_Rect src, dst;
	int WIDTH, HEIGHT;
};

