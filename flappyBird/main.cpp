#include "gameLoop.h"
gameLoop* game = new gameLoop();
int main(int argc, char** argv) {
	double frameStart, frameTime, fps = 75.0;
	double frameDelay = 1000 / fps;
	while (game->getQuit() == false) {
		game->Initialise();
		while (game->getGameState()) {
			frameStart = SDL_GetTicks();
			game->Event();
			game->update();
			game->render();
			if (game->getReplay()) break;
			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < frameDelay) SDL_Delay(frameDelay - frameTime);
		}
		game->clear();
		if (game->getReplay()) {
			delete game;
			game = new gameLoop();
		}
	}

	return 0;
}