#include "pipe.h"

void pipe::render(SDL_Renderer* ren)
{
	if (dst.x + 90 <= 0) {
		setDst(480, 0, 90, 576);
		ranYPos();
	}
	src = getSrc();
	dst = getDst();
	setSrc(0, yPos, 32, 256);
	setDst(dst.x - 2, 0, 90, 576);
	SDL_RenderCopy(ren, getTexture(), &src, &dst);
	box1.x = dst.x; box1.y = 0;
	box1.w = 90; box1.h = 2.25 * (176 - yPos);
	box2.x = dst.x; box2.y = 2.25 * (176 - yPos + 64);
	box2.w = 90; box2.h = 576 - 2.25 * (176 - yPos + 64);
}
void pipe:: ranYPos() {
	srand(time(0));
	yPos = rand() % 97 + 32;
}
void pipe::renderDie(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, getTexture(), &src, &dst);
}