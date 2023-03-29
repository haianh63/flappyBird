#include "bird.h"

void bird::render(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect srcRect,SDL_Rect dstRect)
{
	SDL_RenderCopy(ren, tex, &srcRect, &dstRect);
}
