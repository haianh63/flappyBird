#include "bird.h"


void bird::fall()
{
	velocity += 0.3;
	yPos = yPos + velocity;
	if (yPos + 33 > 576) yPos = 543;
	setDst(200, yPos, 47, 33);
	if (velocity > 0) {
		isJumping = false;
	}
	if (isJumping == true) {
		time = 0;
		angle = -25;
	}
	else if (isJumping == false) {
		time++;
		if (time >=20) {
			angle += 5;
			if (angle >= 90) angle = 90;
		}
	}
}

void bird::jump()
{
	velocity = -6.6;
	isJumping = true;
}



void bird::render(SDL_Renderer* ren)
{
	animationTimer++;
	if (animationTimer > 48) animationTimer = 0;
	src = getSrc(), dst = getDst();
	if (animationTimer <= 16) SDL_RenderCopyEx(ren, getTexture(), &src, &dst, angle, nullptr, SDL_FLIP_NONE);
	else if (16 < animationTimer && animationTimer <= 32) SDL_RenderCopyEx(ren, text2, &src, &dst, angle, nullptr, SDL_FLIP_NONE);
	else if (32 < animationTimer && animationTimer <= 48) SDL_RenderCopyEx(ren, text3, &src, &dst, angle, nullptr, SDL_FLIP_NONE);	
}
void bird::createTexture2(const char* filepath, SDL_Renderer* renderer)
{
	text2 = textureManager::loadTexture(filepath, renderer);
}

void bird::createTexture3(const char* filepath, SDL_Renderer* renderer)
{
	text3 = textureManager::loadTexture(filepath, renderer);
}

bool bird::checkCollision(SDL_Rect rect)
{
	if (dst.y > rect.y+ rect.h || dst.y + dst.h < rect.y || dst.x > rect.x +rect.w || dst.x + dst.w < rect.x) {
		return false;
	}
	return true;
}
void bird::renderDie(SDL_Renderer* ren) {
	src = getSrc(), dst = getDst();
	SDL_RenderCopyEx(ren, getTexture(), &src, &dst, angle, nullptr, SDL_FLIP_NONE);
}