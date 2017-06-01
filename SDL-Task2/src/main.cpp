#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using std::cerr;

const unsigned int SCREEN_WIDTH = 640;
const unsigned int SCREEN_HEIGHT = 480;

//coor 20 20 ing size: 200 200

int main(int args, char* argc[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* imageSurface = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Failed to initialize SDL.\n";
	}

	window = SDL_CreateWindow("Task 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	screenSurface = SDL_GetWindowSurface(window);



	//Initialize PNG loading
	imageSurface = IMG_Load("dvestandvesta.png");
	if(imageSurface == NULL)
	{
		std::cerr << "Cant load image.\n";
	}


		bool quit = false;
		SDL_Event e;

		while(! quit)
		{
			while(SDL_PollEvent(&e) != 0)
			{
				if(e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
			//to display an image in the window
			SDL_Rect rect;
			rect.h = 200;
			rect.w = 200;
			rect.x = 20;
			rect.y = 20;
			SDL_BlitSurface(imageSurface, NULL, screenSurface, &rect);
			SDL_UpdateWindowSurface(window);
		}

	return 0;
}
