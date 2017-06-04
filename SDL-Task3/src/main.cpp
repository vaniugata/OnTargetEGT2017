#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
using std::cerr;
#include "Picture.h"

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


SDL_Window* gWindow = NULL;

SDL_Renderer* gWindowRenderer = NULL;

SDL_Texture* gCurrentTexture = NULL;


//function declarations
SDL_Texture* loadTexture(std::string path);

void close();

int main(int args, char* argc[])
{
	gWindow = SDL_CreateWindow("Task 3", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(gWindow == NULL)
	{
		std::cerr << "Failed to create window.\n";
	}

	gWindowRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if(gWindowRenderer == NULL)
	{
		std::cerr << "Failed to create window renderer.\n";
	}

	SDL_SetRenderDrawColor(gWindowRenderer, 0x00, 0x00, 0x00, 0x00);

	//initialize image
	int imgFlags = IMG_INIT_PNG;
	if(! (IMG_Init(imgFlags) & imgFlags))
	{
		std::cerr << "Failed to initalize png image.\n";
	}

	//Load image texture
	gCurrentTexture = loadTexture("pik4ar.png");
	if(gCurrentTexture == NULL)
	{
		std::cerr << "Failed to load picture from file.\n";
	}

	bool quit = false;
	SDL_Event e;
	Picture picture;
	while(! quit)
	{
		SDL_Rect rect {20, 20, 200, 200};
		while(SDL_PollEvent(&e) != 0)
		{
			switch(e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_MOUSEBUTTONDOWN:
				{
					SDL_RenderClear(gWindowRenderer);
					picture.handleEvent(&e, rect);
					picture.render(*gWindowRenderer, *gCurrentTexture, rect);
					break;
				}
			} //end of switch
		} //end of nested loop
	} //end of main loop

	close();

	return 0;
}
//function imlementation

SDL_Texture* loadTexture(std::string path)
{
	SDL_Texture* resultTexture = NULL;

	//load image
	SDL_Surface* imageSurface = IMG_Load(path.c_str());
	if(imageSurface == NULL)
	{
		std::cerr << "Faled to load image in surface.\n";
	}

	resultTexture = SDL_CreateTextureFromSurface(gWindowRenderer, imageSurface);
	if(resultTexture == NULL)
	{
		std::cerr << "Failed to Create texture form surface(for the picture).";
	}

	SDL_FreeSurface(imageSurface);

	return resultTexture;
}

void close()
{
    //Free loaded image
    SDL_DestroyTexture( gCurrentTexture );
    gCurrentTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( gWindowRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gWindowRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
