#include "background.h"

void background::render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}
