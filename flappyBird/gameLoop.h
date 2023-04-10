#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "textureManager.h"
#include "bird.h"
#include "background.h"
using namespace std;
class gameLoop
{
private:
	const int HEIGHT = 640;
	const int WIDTH = 800;
	bool gameState;
	SDL_Event event;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bird bird;
	background background;
	SDL_Rect srcRect, dstRect;
public:
	bool getGameState() { return gameState; }
	void update();
	gameLoop();
	void Initialise();
	void Event();
	void render();
	void clear();
};

