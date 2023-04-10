#include "bird.h"


void bird::fall()
{
	if (jumpState()) {
		accelerator1 += 0.035;
		accelerator2 += 0.035;
		jumpHeight = jumpHeight + gravity;
		yPos = yPos + accelerator1 + accelerator2 + gravity + jumpHeight;
		setDst(10, yPos, 34, 24);
		if (jumpHeight > 0) {
			isJumping = false;
			jumpHeight = -10;
		}
	}
	else {
		accelerator1 += 0.035;
		accelerator2 += 0.035;
		yPos = yPos + accelerator1 + accelerator2 + gravity;
		setDst(10, yPos, 34, 24);
	}
}

void bird::jump()
{
	if (currentJump - lastJump > 0) {
		accelerator1 = 0;
		accelerator2 = 0;
		isJumping = true;
		lastJump = currentJump;
	}
	else fall();

}



void bird::render(SDL_Renderer* ren)
{
	animationTimer++;
	src = getSrc(), dst = getDst();
	if (animationTimer <= 16) SDL_RenderCopyEx(ren, getTexture(), &src, &dst, angle, nullptr, SDL_FLIP_NONE);
	else if (16 < animationTimer && animationTimer <= 32) SDL_RenderCopyEx(ren, text2, &src, &dst, angle, nullptr, SDL_FLIP_NONE);
	else if (32 < animationTimer && animationTimer <= 48) SDL_RenderCopyEx(ren, text3, &src, &dst, angle, nullptr, SDL_FLIP_NONE);
	else animationTimer = 0;
}
void bird::createTexture2(const char* filepath, SDL_Renderer* renderer)
{
	text2 = textureManager::loadTexture(filepath, renderer);
}

void bird::createTexture3(const char* filepath, SDL_Renderer* renderer)
{
	text3 = textureManager::loadTexture(filepath, renderer);
}
