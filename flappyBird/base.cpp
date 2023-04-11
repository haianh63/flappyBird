#include "base.h"

void base::render(SDL_Renderer* ren)
{
	src = getSrc();
	dst = getDst();
	SDL_RenderCopy(ren, getTexture(), &src, &dst);
	setSrc(src.x + 1, 0, 240, 32);
	if (src.x + 240 > 1600) {
		setSrc(src.x -800, 0, 240, 32);
	}
}
