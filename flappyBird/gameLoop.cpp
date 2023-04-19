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
	pipe[1].setDst(700 + 194 + 90 , 0, 90, 576);
	pipe[1].ranYPos();
}

void gameLoop::Initialise()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	window = SDL_CreateWindow("my game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	if (window == nullptr) cout << "Window is not created!"<<endl;
	else {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr) cout << "Renderer is not created!" << endl;
		else {
			cout << "Initialisation is  successful!" << endl;
			gameState = true;
			isHitSound = true, isDieSound = true;
			bird.createTexture("asset/midBird.png", renderer);
			bird.createTexture2("asset/upBird.png", renderer);
			bird.createTexture3("asset/downBird.png", renderer);
			background.createTexture("asset/Background.png", renderer);
			base.createTexture("asset/base.png", renderer);
			pipe[0].createTexture("asset/pipe.png", renderer);
			pipe[1].createTexture("asset/pipe.png", renderer);
			scoreBox.loadFont("asset/font.ttf", 60);
			dieSound.loadSound("asset/die.wav");
			hitSound.loadSound("asset/hit.wav");
			wingSound.loadSound("asset/wing.wav");
			pointSound.loadSound("asset/point.wav");
			swooshSound.loadSound("asset/swoosh.wav");
			gameOver.createTexture("asset/gameOver.png", renderer);
			newGameOver.createTexture("asset/newGameOver.png", renderer);
			dieScore.loadFont("asset/font.ttf", 40);
			read.open("asset/bestScore.txt");
			isNewRecord = false;
			replay.createTexture("asset/replay.png", renderer);
			replay.setWidthHeight(130, 72);
			isReplay = false;
			isQuit = false;
			message.createTexture("asset/message.png", renderer);
			message.setWidthHeight(276, 400);
			isIntro = true;
		}

	}
}

void gameLoop::Event()
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		gameState = false;
		isQuit = true;
	}
	if (isIntro == true) {
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			cout << "clicked!" << endl;
			isIntro = false;
			wingSound.playSound();
			bird.jump();
		}
	}
	else {
		if (bird.getDie() == false && event.type == SDL_MOUSEBUTTONDOWN) {
			wingSound.playSound();
			bird.jump();
		}
		else bird.fall();
		if (event.type == SDL_MOUSEBUTTONDOWN && bird.getDie() == true && bird.getYPos() > 542.99) {
			SDL_GetMouseState(&xPos, &yPos);
			if (175 <= xPos && xPos <= 305 && 454 <= yPos && yPos <= 526) isReplay = true;
		}
	}
}

void gameLoop::render()
{
	if (bird.getDie() == false) {
		if (pipe[0].getDst().x == 200 || pipe[1].getDst().x == 200) {
			pointSound.playSound();
			score++;
		}
		scoreBox.setText(to_string(score), renderer);
		SDL_RenderClear(renderer);
		background.render(renderer);
		bird.render(renderer);
		pipe[0].render(renderer);
		pipe[1].render(renderer);
		base.render(renderer);
		scoreBox.draw(renderer,250,110);
		SDL_RenderPresent(renderer);
	}
	else if (bird.getDie() == true) {
		if (bird.getYPos() <= 542.99) {
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
			scoreBox.draw(renderer,250,110);
			SDL_RenderPresent(renderer);
		}
		else {
			read >> bestScore;
			if (score > bestScore) {
				write.open("asset/bestScore.txt", ios::trunc | ios::out);
				write << score;
				bestScore = score;
				isNewRecord = true;
			}
			dieScore.setText(to_string(score), renderer);
			SDL_RenderClear(renderer);
			background.render(renderer);
			pipe[0].renderDie(renderer);
			pipe[1].renderDie(renderer);
			bird.renderDie(renderer);
			base.renderDie(renderer);
			if (isNewRecord) {
				newGameOver.render(renderer);
			}
			else {
				gameOver.render(renderer);
			}
			replay.render(renderer, 240, 490);
			dieScore.draw(renderer, 362, 316);
			dieScore.setText(to_string(bestScore), renderer);
			dieScore.draw(renderer, 362, 386);
			SDL_RenderPresent(renderer);
		}
	}
	if (bird.checkCollision(pipe[0].getBox1()) || bird.checkCollision(pipe[0].getBox2())
	 || bird.checkCollision(pipe[1].getBox1()) || bird.checkCollision(pipe[1].getBox2())) {
		if (isHitSound) {
			hitSound.playSound();
			isHitSound = false;
		}
		bird.setDie(true);
		if (isDieSound) {
			dieSound.playSound();
			isDieSound = false;
		}
	}
}

void gameLoop::clear()
{
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	read.close();
	write.close();
}
void gameLoop::intro() {
	background.render(renderer);
	bird.renderDie(renderer);
	base.renderIntro(renderer);
	message.render(renderer, 240, 290);
	SDL_RenderPresent(renderer);
}
