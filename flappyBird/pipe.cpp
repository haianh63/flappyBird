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
}
void pipe:: ranYPos() {
	srand(time(0));
	yPos = rand() % 97 + 32;
}
