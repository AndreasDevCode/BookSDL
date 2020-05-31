
#include "Game.h"

int main(int argc, char** argv)
{
	Game game;
	bool sucess = game.Initialize();
	while (sucess)
	{
		game.RunLoop();
	}
	game.Shutdown();

	return 0;
}