#include "Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using std::cerr;

Game::Game() : m_window(nullptr),
			m_renderer(nullptr),
			m_backgroundTexture(nullptr),
			m_figuresTexture(nullptr),
			m_e(),
			m_eGameState(PLAY)
{
	Init();
	LoadMedia();
}

Game::~Game()
{
	Free();
	SDL_Quit();
}

void Game::Init()
{

	m_window = SDL_CreateWindow("Chess", \
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, \
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(m_window == nullptr)
	{
		std::cerr << "Failed to create window.";
		return;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, \
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(m_renderer == nullptr)
	{
		std::cerr << "Faled to create renderer.";
	}
}

void Game::LoadMedia()
{
	SDL_Surface* loadedSurface = IMG_Load("chessboard.jpg");
	if(loadedSurface == nullptr)
	{
		std::cerr << "Failed to load media.";
	}

	m_backgroundTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
	if(m_backgroundTexture == nullptr)
	{
		std::cerr << "Failed to convert texture from surface.";
		return;
	}

	SDL_FreeSurface(loadedSurface);

	loadedSurface = IMG_Load("chess-figures.png");
	if(loadedSurface == nullptr)
	{
		std::cerr << "Failed to convert texture from surface.";
		return;
	}

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 255 ,255) );

	m_figuresTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
	if(m_backgroundTexture == nullptr)
	{
		std::cerr << "Failed to convert texture from surface.";
		return;
	}

	SDL_FreeSurface(loadedSurface);
	loadedSurface = nullptr;
}

void Game::Free()
{
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
	SDL_DestroyTexture(m_backgroundTexture);
	m_backgroundTexture = nullptr;
	SDL_DestroyTexture(m_figuresTexture);
	m_figuresTexture = nullptr;
}

void Game::ShowMouseCoords()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	std::cerr << "x: " << x << " y: " << y << "\n";
}

void Game::RenderChessFigures()
{
	//Display pawns
	for(int i = 0; i < BOARD_X_POSITIONS; i++)
	{
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
				&m_mapFiguresTextures["wPawn"], &m_arrOnScreen[6][i]);
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
				&m_mapFiguresTextures["bPawn"], &m_arrOnScreen[1][i]);

	}
	//Whites
	//Left flange
	SDL_RenderCopy(m_renderer, m_figuresTexture,\
			&m_mapFiguresTextures["bTop"], &m_arrOnScreen[0][0]);
	SDL_RenderCopy(m_renderer, m_figuresTexture,\
				&m_mapFiguresTextures["bHorse"], &m_arrOnScreen[0][1]);
	SDL_RenderCopy(m_renderer, m_figuresTexture,\
				&m_mapFiguresTextures["bOfficer"], &m_arrOnScreen[0][2]);

	//Middle
	SDL_RenderCopy(m_renderer, m_figuresTexture,\
					&m_mapFiguresTextures["bQueen"], &m_arrOnScreen[0][3]);
	SDL_RenderCopy(m_renderer, m_figuresTexture,\
					&m_mapFiguresTextures["bKing"], &m_arrOnScreen[0][4]);
	//Right flange
	SDL_RenderCopy(m_renderer, m_figuresTexture,\
				&m_mapFiguresTextures["bTop"], &m_arrOnScreen[0][5]);
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
					&m_mapFiguresTextures["bHorse"], &m_arrOnScreen[0][6]);
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
					&m_mapFiguresTextures["bOfficer"], &m_arrOnScreen[0][7]);

		//Blacks
		//Left flange
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
				&m_mapFiguresTextures["wTop"], &m_arrOnScreen[7][0]);
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
					&m_mapFiguresTextures["wHorse"], &m_arrOnScreen[7][1]);
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
					&m_mapFiguresTextures["wOfficer"], &m_arrOnScreen[7][2]);

		//Middle
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
						&m_mapFiguresTextures["wQueen"], &m_arrOnScreen[7][3]);
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
						&m_mapFiguresTextures["wKing"], &m_arrOnScreen[7][4]);
		//Right flange
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
					&m_mapFiguresTextures["wTop"], &m_arrOnScreen[7][5]);
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
					&m_mapFiguresTextures["wHorse"], &m_arrOnScreen[7][6]);
		SDL_RenderCopy(m_renderer, m_figuresTexture,\
					&m_mapFiguresTextures["wOfficer"], &m_arrOnScreen[7][7]);

	SDL_RenderPresent(m_renderer);
}

void Game::Play()
{
	while(SDL_PollEvent(&m_e) > 0)
	{

		switch(m_e.type)
		{
		case SDL_QUIT:
			m_eGameState = QUIT;
			break;

		case SDL_MOUSEMOTION:
			ShowMouseCoords();
			break;

		case SDL_MOUSEBUTTONDOWN:
			RenderChessFigures();
		break;
		}

		switch(m_e.key.keysym.sym)
		{
		case SDLK_SPACE:

			break;
		}
	}
}

void Game::RenderGameBoard()
{
	int x = (SCREEN_WIDTH - BACKGROUND_WIDTH) / 2;
	int y = 0;
	SDL_Rect backgroundRect {x, y, 700, 700};
	SDL_RenderCopy(m_renderer, m_backgroundTexture, NULL, &backgroundRect);
	SDL_RenderPresent(m_renderer);
}

void Game::RenderScreenMatrix()
{
	SDL_Rect boardSquare {201, 38, FIGURE_WIDTH, FIGURE_HEIGHT};

	for(int i = 0; i < BOARD_X_POSITIONS; i++)
	{
		for(int j = 0; j < BOARD_Y_POSITIONS; j++)
		{
			m_arrOnScreen[i][j] = boardSquare;
			boardSquare.x += FIGURE_WIDTH + PIXEL_STEP;
		}
		boardSquare.x = 201;
		boardSquare.y += FIGURE_HEIGHT + PIXEL_STEP;
	}
}

void Game::CopyFiguresToMap()
{
	SDL_Rect textureRow1 {0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT};

	for(int i = 0; i < TEXTURE_ROWS; i++)
	{
		textureRow1.y = i * TEXTURE_HEIGHT;
		for(int j = 0; j < NUMBER_OF_FIGURES; j++)
		{
			m_vecFromTexture.push_back(textureRow1);
			textureRow1.x += TEXTURE_WIDTH;
		}
		textureRow1.x = 0;
	}

	m_mapFiguresTextures["bTop"] 		= m_vecFromTexture[0];
	m_mapFiguresTextures["bOfficer"] 	= m_vecFromTexture[1];
	m_mapFiguresTextures["bKing"] 		= m_vecFromTexture[2];
	m_mapFiguresTextures["bQueen"]		= m_vecFromTexture[3];
	m_mapFiguresTextures["bHorse"]		= m_vecFromTexture[4];
	m_mapFiguresTextures["bPawn"]		= m_vecFromTexture[5];

	m_mapFiguresTextures["wTop"] 		= m_vecFromTexture[6];
	m_mapFiguresTextures["wOfficer"] 	= m_vecFromTexture[7];
	m_mapFiguresTextures["wKing"] 		= m_vecFromTexture[8];
	m_mapFiguresTextures["wQueen"]		= m_vecFromTexture[9];
	m_mapFiguresTextures["wHorse"]		= m_vecFromTexture[10];
	m_mapFiguresTextures["wPawn"]		= m_vecFromTexture[11];
}
