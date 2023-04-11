#include "gameLoop.h"
gameLoop* game = new gameLoop();
int main(int argc, char** argv) {
	double frameStart, frameTime, fps = 66.0;
	double frameDelay = 1000 / fps;
	game->Initialise();
	while (game -> getGameState()) {
		frameStart = SDL_GetTicks();
		game->Event();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay) SDL_Delay(frameDelay - frameTime);
	}
	game->clear();
	return 0;
}