#include "gameLoop.h"

void gameLoop::update()
{
	
}

gameLoop::gameLoop()
{
	window = nullptr;
	renderer = nullptr;
	gameState = false;
	bird.setSrc(0, 0, 34, 24);
	bird.setDst(10, 10, 34, 24);
}

void gameLoop::Initialise()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("my game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	if (window == nullptr) cout << "Window is not created!"<<endl;
	else {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr) cout << "Renderer is not created!" << endl;
		else {
			cout << "Initialisation is  successful!" << endl;
			gameState = true;
			bird.createTexture("asset/midBird.png", renderer);
			background.createTexture("asset/Background.png", renderer);
		}
	}
}

void gameLoop::Event()
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) gameState = false;
	if (event.type == SDL_MOUSEBUTTONDOWN) cout << "Pressed!"<<endl;
	if (event.type == SDL_MOUSEMOTION) cout << event.motion.x << " " << event.motion.y << endl;
}

void gameLoop::render()
{
	SDL_RenderClear(renderer);
	background.render(renderer, background.getTexture());
	bird.render(renderer, bird.getTexture(), bird.getSrc(), bird.getDst());
	SDL_RenderPresent(renderer);
}

void gameLoop::clear()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
}
