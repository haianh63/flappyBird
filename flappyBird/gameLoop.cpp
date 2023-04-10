#include "gameLoop.h"

void gameLoop::update()
{
	bird.update();
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
			bird.createTexture2("asset/upBird.png", renderer);
			bird.createTexture3("asset/downBird.png", renderer);
			background.createTexture("asset/Background.png", renderer);
		}
	}
}

void gameLoop::Event()
{
	bird.getJumpTime();
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) gameState = false;
	/*if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
			if (!bird.jumpState()) {
				bird.jump();
			}
			else bird.fall();
		}
	}*/
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (!bird.jumpState()) {
			bird.jump();
		}
		else bird.fall();
	}
	else bird.fall();
	//if (event.type == SDL_MOUSEBUTTONDOWN) cout << "Pressed!"<<endl;
	//if (event.type == SDL_MOUSEMOTION) cout << event.motion.x << " " << event.motion.y << endl;
}

void gameLoop::render()
{
	SDL_RenderClear(renderer);
	background.render(renderer);
	bird.render(renderer);
	SDL_RenderPresent(renderer);
}

void gameLoop::clear()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
}
