#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "textureManager.h"
#include "bird.h"
#include "background.h"
#include "base.h"
#include "pipe.h"
#include "textBox.h"
#include "sound.h"
using namespace std;
class gameLoop
{
private:
	const int HEIGHT = 640;
	const int WIDTH = 480;
	bool gameState;
	SDL_Event event;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bird bird;
	background background;
	base base;
	SDL_Rect srcRect, dstRect;
	pipe pipe[2];
	textBox scoreBox;
	int score = 0;
	bool increaseScore1 = true;
	bool increaseScore2 = true;
	sound dieSound, hitSound, pointSound, wingSound, swooshSound;
	bool isHitSound, isDieSound;
public:
	bool getGameState() { return gameState; }
	void update();
	gameLoop();
	void Initialise();
	void Event();
	void render();
	void clear();
};

