#include "Object.h"

Object::Object()
{
	text = nullptr;
}

void Object::setSrc(int x, int y, int w, int h)
{
	srcRect.x = x;
	srcRect.y = y;
	srcRect.w = w;
	srcRect.h = h;
}

void Object::setDst(int x, int y, int w, int h)
{
	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = w;
	dstRect.h = h;
}

void Object::createTexture(const char* filepath, SDL_Renderer* renderer)
{
	text = textureManager::loadTexture(filepath, renderer);
}
