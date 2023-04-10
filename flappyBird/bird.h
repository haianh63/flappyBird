#pragma once
#include "Object.h"

class bird:public Object
{
private:
	double yPos = 200;
	double gravity = 0.5;
	bool isJumping = false;
	double jumpHeight = -10;
	double accelerator1 = 0, accelerator2 = 0;
	double lastJump = 0;
	double currentJump;
	double animationTimer = 0;
	SDL_Texture* text2;
	SDL_Texture* text3;
	SDL_Rect src, dst;
	double angle = 0;
public:
	bool jumpState () { return isJumping; }
	void getJumpTime() { currentJump = SDL_GetTicks(); }
	void setAngle(double angle) { this->angle = angle; }
	void jump();
	void fall();
	void update(){}
	void render(SDL_Renderer* ren);
	void createTexture2(const char* filepath, SDL_Renderer* renderer);
	void createTexture3(const char* filepath, SDL_Renderer* renderer);
};

