#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <sstream>

#include "Texture.h"


//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

int main(int args, char* argc[])
{
	gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	Texture::m_Renderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

	if(!TTF_WasInit() && TTF_Init()==-1)
	{
		std::cerr << "TTF_Init: %s\n", TTF_GetError();
	}

	Texture* texture = new Texture();

	SDL_RenderClear( Texture::m_Renderer );
	texture->LoadFromFile("Untitled.png");
	texture->Render();

	SDL_Event e;
	bool quit = false;

	int x, y;

	while(! quit)
	{
		while(SDL_PollEvent(&e))
		{
			switch(e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_MOUSEMOTION:
				{
					SDL_GetMouseState(&x, &y);
					break;
				}
			}// end switch
		} // end nested loop
		texture->LoadFromRenderedText(x, y);
		texture->Render();
		SDL_RenderPresent(Texture::m_Renderer);
		SDL_RenderClear(Texture::m_Renderer);
	} // end main loop

	return 0;
}

