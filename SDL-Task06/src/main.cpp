#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Texture.h"


const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 718;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;



int main(int args, char* argc[])
{

	gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	Texture::m_Renderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

	Texture* texture = new Texture();


	SDL_RenderClear( Texture::m_Renderer );
	texture->LoadFromFile("Untitled.png");

	texture->Render();


	SDL_Event e;
	bool quit = false;

	while(! quit)
	{
		while(SDL_PollEvent(&e) > 0)
		{
			switch(e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		SDL_RenderPresent(Texture::m_Renderer);
	}

	return 0;
}

