#include "Game.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>
using std::cerr;
using std::cout;
#include <sstream>

SDL_Renderer* Game::m_renderer = NULL;
SDL_Window* Game::m_window = NULL;

Game::Game() : m_texture(NULL), m_font(NULL), m_fontTexture(NULL)
{

}

Game::~Game()
{
	Free();
}

void Game::Init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Could not initialize SDL: " << SDL_GetError();
		return;
	}

	if(! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) )
	{
		std::cerr << "SDL image could not initialize: " << SDL_GetError();
		return;
	}

	if(!TTF_WasInit() && TTF_Init()==-1)
	{
		std::cerr << "TTF_Init: %s\n", TTF_GetError();
		return;
	}

	Game::m_window = SDL_CreateWindow("Flip cards", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			  SCREEN_WIDTH, SCREEN_HIEGHT, SDL_WINDOW_SHOWN);


	Game::m_renderer = SDL_CreateRenderer(Game::m_window, -1, SDL_RENDERER_ACCELERATED);
}

void Game::Render(SDL_Rect& from, SDL_Rect& to)
{
	SDL_RenderCopy(m_renderer, m_texture, &from, &to);
}

void Game::LoadFromFile(std::string fileName)
{
	//Free();
	SDL_Surface* loadedSurface = IMG_Load( fileName.c_str() );
	if( loadedSurface == NULL )
	{
		std::cerr <<  "Unable to load image " <<  fileName.c_str() << "! SDL_image Error: " << IMG_GetError();
	}

	SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 181, 230, 29) );

	m_texture = SDL_CreateTextureFromSurface( m_renderer, loadedSurface );
	if( m_texture == NULL )
	{
		std:: cerr << "Unable to create texture from %s! SDL Error: %s\n", fileName.c_str(), SDL_GetError();
	}

	SDL_FreeSurface(loadedSurface);

	m_font = TTF_OpenFont("Roboto-Regular.ttf", 42);
	if(m_font == NULL)
	{
		std::cerr << "Failed to load font." << SDL_GetError();
	}

	SDL_SetRenderDrawColor(Game::m_renderer, 0, 255, 0, 255);
	SDL_RenderClear(Game::m_renderer);
}

void Game::RenderStart()
{
	SDL_Rect back{0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT};

	SDL_Rect current;
	current.w = TEXTURE_WIDTH;
	current.h = TEXTURE_HEIGHT;

	for(int i = 0; i < BOARD_ROWS; i++)
	{
		for(int j = 0; j < BOARD_COLS; j++)
		{
			current.x = j * TEXTURE_WIDTH;
			current.y = i * TEXTURE_HEIGHT;
			Render(back, current);
			m_vecCardsOnScreen.push_back(current);
		}
	}
	SDL_RenderPresent(Game::m_renderer);
}

void Game::RenderCards()
{
	SDL_Rect textureRect;
	textureRect.w = TEXTURE_WIDTH;
	textureRect.h = TEXTURE_HEIGHT;
	textureRect.y = 100;//second row in the picture
	for(int i = 0; i < NUMBER_OF_SPRITES - 1; ++i)
	{
		textureRect.x = i * TEXTURE_WIDTH;
		m_vecSprites.push_back(textureRect);
	}


	SDL_Rect current;
		current.w = TEXTURE_WIDTH;
		current.h = TEXTURE_HEIGHT;

		for(int i = 0; i < BOARD_ROWS; i++)
		{
			for(int j = 0; j < BOARD_COLS; j++)
			{
				current.x = j * TEXTURE_WIDTH;
				current.y = i * TEXTURE_HEIGHT;
				m_vecCardsOnScreen.push_back(current);
			}
		}
}

void Game::Free()
{
	SDL_DestroyTexture(m_texture);
	m_texture = NULL;
	SDL_DestroyTexture(m_fontTexture);
	m_fontTexture = NULL;

	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}

void Game::FlipCard()
{
	int i = CardIndex();
	SDL_RenderCopy(Game::m_renderer, m_texture, &m_vecSprites[i], &m_vecCardsOnScreen[i]);
	SDL_RenderPresent(m_renderer);
}

void Game::ShowMouseCoords()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	SDL_Color textColor {255, 255, 255, 255};
	SDL_Rect textRect {0, 0, 100, 25};

	std::stringstream coords;
	coords << "x: " <<  x << " y: " << y;

	SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, coords.str().c_str(), textColor);
	m_fontTexture = SDL_CreateTextureFromSurface(Game::m_renderer, textSurface);
	SDL_FreeSurface(textSurface);

	SDL_RenderCopy(Game::m_renderer, m_fontTexture, NULL, &textRect);
	SDL_RenderPresent(Game::m_renderer);
	SDL_RenderClear(Game::m_renderer);
}

void Game::DeleteCard()
{
	static int bFlippedCards[NUMBER_OF_SPRITES] {};

	int index = CardIndex();

	bFlippedCards[index]++;

	for(int i = 0; i < NUMBER_OF_SPRITES; i++)
	{
		if(bFlippedCards[i] > 1)
		{
			SDL_RenderFillRect(m_renderer, &m_vecCardsOnScreen[i]);
			SDL_RenderPresent(m_renderer);
		}
	}
}

int Game::CardIndex()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	//convert to get current rect
	int xCardRect = x / TEXTURE_WIDTH;
	int yCardRect = y / TEXTURE_HEIGHT;

	if(yCardRect > 0)
	{
		xCardRect += 3;
	}

	return xCardRect;
}

void Game::ViewRects()
{
	for(int i = 0; i <= (int)m_vecSprites.size(); i++)
		{
			std::cout << i <<" x: " << m_vecSprites[i].x
					<< " y: " << m_vecSprites[i].y
					<< " w: " << m_vecSprites[i].w
					<< " h: " << m_vecSprites[i].h
					<< std::endl;
		}
	/*for(int i = 0; i <= (int)m_vecCardsOnScreen.size(); i++)
	{
		std::cout << i <<" x: " << m_vecCardsOnScreen[i].x
				<< " y: " << m_vecCardsOnScreen[i].y
				<< " w: " << m_vecCardsOnScreen[i].w
				<< " h: " << m_vecCardsOnScreen[i].h
				<< std::endl;
	}*/
}
