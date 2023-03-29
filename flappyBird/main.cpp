#include "gameLoop.h"
gameLoop* game = new gameLoop();
int main(int argc, char** argv) {
	game->Initialise();
	while (game -> getGameState()) {
		game->render();
		game->Event();
		game->update();
	}
	game->clear();
	return 0;
}