#include <iostream>
#include "game.hpp"

int main()
{
	Game game;

	// Game loop
	while (game.running())
	{
		game.updateDt();
		game.update();
		game.render();
	}

	return 0;
}