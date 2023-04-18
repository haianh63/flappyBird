#include "button.h"

void button::render(SDL_Renderer* ren,int x,int y)
{
	setDst(x - WIDTH / 2, y - HEIGHT / 2, WIDTH, HEIGHT);
	dst = getDst();
	SDL_RenderCopy(ren, getTexture(), nullptr, &dst);
}
