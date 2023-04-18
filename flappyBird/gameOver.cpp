#include "gameOver.h"

void gameOver::render(SDL_Renderer* ren)
{
	setDst(480 / 2 - WIDTH / 2, 550 / 2 - HEIGHT / 2, WIDTH, HEIGHT);
	dst = getDst();
	SDL_RenderCopy(ren, getTexture(), nullptr, &dst);
}
