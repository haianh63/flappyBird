#pragma once
#include "Object.h"

class bird:public Object
{
private:
	double yPos = 200;
	double gravity = 0.3;
	bool isJumping = false;
	double velocity = 0;
	double animationTimer = 0;
	SDL_Texture* text2;
	SDL_Texture* text3;
	SDL_Rect src, dst;
	double angle = 0;
	double time = 0;
public:
	bool jumpState () { return isJumping; }
	void setAngle(double angle) { this->angle = angle; }
	void jump();
	void fall();
	void update(){}
	void render(SDL_Renderer* ren);
	void createTexture2(const char* filepath, SDL_Renderer* renderer);
	void createTexture3(const char* filepath, SDL_Renderer* renderer);
};

