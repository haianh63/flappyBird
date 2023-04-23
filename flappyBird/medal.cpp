#include "medal.h"

void medal::render(SDL_Renderer* ren, int x, int y)
{
	setDst(x, y, WIDTH, HEIGHT);
	dst = getDst();
	SDL_RenderCopy(ren, getTexture(), nullptr, &dst);
}
