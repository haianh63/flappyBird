#include "background.h"

void background::render(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect srcRect, SDL_Rect dstRect)
{
	SDL_RenderCopy(ren, tex, &srcRect, &dstRect);
}

void background::render(SDL_Renderer* ren, SDL_Texture* tex)
{
	SDL_RenderCopy(ren, tex, NULL, NULL);
}
