//1. Напишете програма която да генерира случайни правоъгълници на екрана
//- на случайни ккординати, със случайни размери и цвят.
#include <SDL2/SDL.h>
#include "Globals.h"
#include "Rectangle.h"
#include <memory>

int main(int args, char* argc[])
{
	SDL_Window* gWindow = SDL_CreateWindow("Rectangles",\
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,\
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* gRenderer = SDL_CreateRenderer(gWindow, -1,\
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Event e;
	bool quit = false;

	while(! quit)
	{
		Rectangle rectangle;
		rectangle.Draw(gRenderer);
		while(SDL_PollEvent(&e) > 0)
		{
			switch(e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
	}

	return 0;
}
