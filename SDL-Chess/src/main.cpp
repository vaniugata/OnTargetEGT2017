#include <SDL2/SDL_main.h>

#include "Game.h"

int main(int args, char* argc[])
{
	Game* game = new Game();

	game->RenderGameBoard();
	game->RenderScreenMatrix();
	game->CopyFiguresToMap();
	while(game->m_eGameState != QUIT)
	{
		game->Play();
	}

	game->~Game();

	return 0;
}
