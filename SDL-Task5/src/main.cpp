#include "Game.h"

int main(int args, char* argc[])
{
	Game* game = new Game();
	game->Init();
	game->LoadMedia();
	game->RenderBoard();
	SDL_Event e;

	while(game->m_enumGameState != QUIT)
	{
		game->Play(&e);
	}

	return 0;
}
