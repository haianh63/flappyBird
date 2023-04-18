#pragma once
#include "textureManager.h"
using namespace std;
class Object
{
private:
	SDL_Rect srcRect, dstRect;
	SDL_Texture* text;
public:
	Object();
	SDL_Texture* getTexture() { return text; }
	SDL_Rect getSrc() { return srcRect; }
	SDL_Rect getDst() { return dstRect; }
	void setSrc(int x,int y,int w,int h);
	void setDst(int x, int y, int w, int h);
	void createTexture(const char* filepath, SDL_Renderer* renderer);
	void virtual render(SDL_Renderer* ren) {}
	~Object();
};

