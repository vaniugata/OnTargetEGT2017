#include "Game.h"
#include "globals.hpp"


int main(int args, char* argc[])
{
	Game* game = new Game();
	game->Init();
	game->LoadFromFile("sprites.png");
	game->RenderCards();
	game->RenderStart();

	bool quit = false;
	SDL_Event e;

	while(! quit)
	{
		while(SDL_PollEvent(&e) > 0)
		{
			switch(e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_MOUSEBUTTONDOWN:
					game->FlipCard();
					game->DeleteCard();
			break;
			}
		}//nested loop
	}// main loop

	game->~Game();
	return 0;
}



