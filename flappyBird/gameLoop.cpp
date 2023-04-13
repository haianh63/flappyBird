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
	bird.setDst(200, 296, 47, 33);
	base.setSrc(0,0 , 240, 32);
	base.setDst(0, 576, 480, 64);
	pipe[0].setDst(700, 0, 90, 576);
	pipe[0].ranYPos();
	pipe[1].setDst(700 + 195 + 90 , 0, 90, 576);
	pipe[1].ranYPos();
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
			base.createTexture("asset/base.png", renderer);
			pipe[0].createTexture("asset/pipe.png", renderer);
			pipe[1].createTexture("asset/pipe.png", renderer);
		}
	}
}

void gameLoop::Event()
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) gameState = false;
	if (bird.getDie() == false && event.type == SDL_MOUSEBUTTONDOWN) {
		bird.jump();
	}
	else bird.fall();
}

void gameLoop::render()
{
	if (bird.getDie() == false) {
		SDL_RenderClear(renderer);
		background.render(renderer);
		bird.render(renderer);
		pipe[0].render(renderer);
		pipe[1].render(renderer);
		base.render(renderer);
		SDL_RenderPresent(renderer);
	}
	else if (bird.getDie() == true && bird.getYPos() <= 542.99) {
		if (bird.getVel() < 0) {
			bird.setVel(0);
			bird.setJumpState(false);
		}
		SDL_RenderClear(renderer);
		background.render(renderer);
		pipe[0].renderDie(renderer);
		pipe[1].renderDie(renderer);
		bird.render(renderer);
		base.renderDie(renderer);
		SDL_RenderPresent(renderer);
	}
	cout << bird.getYPos() << endl;
	if (bird.checkCollision(pipe[0].getBox1()) || bird.checkCollision(pipe[0].getBox2())
	 || bird.checkCollision(pipe[1].getBox1()) || bird.checkCollision(pipe[1].getBox2())) {
		bird.setDie(true);
	}
}

void gameLoop::clear()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
}
