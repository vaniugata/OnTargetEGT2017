#include "Game.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using std::cerr;
#include <string>

SDL_Window* Game::m_window = nullptr;
SDL_Renderer* Game::m_renderer = nullptr;

bool Game::m_bBoard[BOARD_WIDTH_POSITIONS][BOARD_HEIGHT_POSITIONS] {false};
int Game::m_iMovesMade[BOARD_WIDTH_POSITIONS][BOARD_HEIGHT_POSITIONS] {0};

Game::Game() : m_enumGameState(PLAY),
			m_texture(nullptr),
			m_playerTexture(nullptr),
			m_font(nullptr)
{}

Game::~Game()
{
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;
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

	Game::m_window = SDL_CreateWindow("Flip cards",	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	Game::m_renderer = SDL_CreateRenderer(Game::m_window, -1, SDL_RENDERER_ACCELERATED);
}

void Game::LoadMedia()
{
	std::string board = "checkboard.png";

	SDL_Surface* loadedSurface = IMG_Load( board.c_str() );
	if( loadedSurface == NULL )
	{
		std::cerr <<  "Unable to load image " <<  board.c_str() << "! SDL_image Error: " << IMG_GetError();
	}

	SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 255, 255, 255) );

	m_texture = SDL_CreateTextureFromSurface( m_renderer, loadedSurface );
	if( m_texture == NULL )
	{
		std:: cerr << "Unable to create texture from %s! SDL Error: %s\n", board.c_str(), SDL_GetError();
	}

	SDL_FreeSurface(loadedSurface);
	loadedSurface = nullptr;

	std::string players = "players.png";

	loadedSurface = IMG_Load( players.c_str() );
	if( loadedSurface == NULL )
	{
		std::cerr <<  "Unable to load image " <<  players.c_str() << "! SDL_image Error: " << IMG_GetError();
	}

	SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 255, 255) );

	m_playerTexture = SDL_CreateTextureFromSurface( m_renderer, loadedSurface );
	if( m_playerTexture == NULL )
	{
		std:: cerr << "Unable to create texture from %s! SDL Error: %s\n", board.c_str(), SDL_GetError();
	}

	SDL_FreeSurface(loadedSurface);
	loadedSurface = nullptr;
	SDL_SetRenderDrawColor(Game::m_renderer, 175, 175, 175, 255);
	SDL_RenderClear(Game::m_renderer);
	SDL_RenderPresent(m_renderer);

	m_font = TTF_OpenFont("Roboto-Light.ttf", 18);
	 if( m_font == NULL )
	{
		std::cerr << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError();
		return;
	}
}

void Game::RenderText(std::string text)
{
	SDL_Color textColor {220, 0, 175};

	SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, text.c_str(), textColor);

	m_texture = SDL_CreateTextureFromSurface(m_renderer, textSurface);

	SDL_FreeSurface(textSurface);
	textSurface = nullptr;

	SDL_RenderClear(m_renderer);
	SDL_Rect textRect {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, 28};
	SDL_RenderCopy(m_renderer, m_texture, NULL, &textRect);
	SDL_RenderPresent(m_renderer);
}

void Game::RenderBoard()
{
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Game::Play(SDL_Event* e)
{
	while(SDL_PollEvent(e) > 0)
	{
		switch(e->type)
		{
		case SDL_QUIT:
			m_enumGameState = QUIT;
			break;

		case SDL_MOUSEBUTTONDOWN:
			if(m_bBoard[GetMousePosition().x][GetMousePosition().y] == false)
			{
				PlacePlayer();
				CheckWin();
			}
			break;

		case SDL_MOUSEMOTION:
			Highlight(255, 0, 0);
			RemoveHighlight();
			break;
		}
	}
}

bool Game::SwitchPlayers()
{

	static bool switchPlayers = false;

		if(! switchPlayers)
		{
			switchPlayers = true;
		}
		else
		{
			switchPlayers = false;
		}
		return switchPlayers;
}

void Game::PlacePlayer()
{
	Check();
	SDL_Rect playerClip {0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT};

	int i = GetMousePosition().y;
	int j = GetMousePosition().x;

	if(SwitchPlayers())
	{
		playerClip.y = 100;
		m_iMovesMade[i][j] = 2;
	}
	else
	{
		m_iMovesMade[i][j] = 1;
	}

	int x, y;
	SDL_GetMouseState(&x, &y);
	int xPos = x / TEXTURE_WIDTH * TEXTURE_WIDTH;
	int yPos = y / TEXTURE_HEIGHT * TEXTURE_HEIGHT;

	SDL_Rect playerPosRect {xPos, yPos, TEXTURE_WIDTH, TEXTURE_HEIGHT};

	SDL_RenderCopy(m_renderer, m_playerTexture, &playerClip, &playerPosRect );
	SDL_RenderPresent(m_renderer);
}

MousePos Game::GetMousePosition()
{
	int x , y;
	SDL_GetMouseState(&x , &y);

	int xPos= x / TEXTURE_WIDTH;
	int yPos = y / TEXTURE_HEIGHT;

	MousePos mp;
	mp.x = xPos;
	mp.y = yPos;

	return mp;
}

void Game::Check()
{
	m_bBoard[GetMousePosition().x][GetMousePosition().y] = true;
}

void Game::Highlight(int r, int g, int b)
{
	MousePos mp = GetMousePosition();
	mp.x *= TEXTURE_WIDTH;
	mp.y *= TEXTURE_HEIGHT;

	int border = 10;
	int spacing = 5;
	SDL_Rect highlightRect {mp.x + spacing, mp.y + spacing, TEXTURE_WIDTH - border, TEXTURE_HEIGHT - border};
	SDL_SetRenderDrawColor(m_renderer, r, g, b, 0);
	SDL_RenderDrawRect(m_renderer, &highlightRect);
	SDL_RenderPresent(m_renderer);
}

void Game::RemoveHighlight()
{
	MousePos mp = GetMousePosition();
	mp.x *= TEXTURE_WIDTH;
	mp.y *= TEXTURE_HEIGHT;

	int border = 10;
	int spacing = 5;
	SDL_Rect highlightRect {mp.x + spacing, mp.y + spacing, TEXTURE_WIDTH - border, TEXTURE_HEIGHT - border};
	SDL_SetRenderDrawColor(Game::m_renderer, 175, 175, 175, 255);
	SDL_RenderDrawRect(m_renderer, &highlightRect);
}

void Game::CheckWin()
{
	//diagonal win
	if(((m_iMovesMade[0][0] == m_iMovesMade[1][1]) &&
			(m_iMovesMade[0][0] == m_iMovesMade[2][2]) &&
			(m_iMovesMade[0][0] == 1) ) ||
				((m_iMovesMade[0][2] == m_iMovesMade[1][1]) &&
				(m_iMovesMade[1][1] == m_iMovesMade[2][0]) &&
				(m_iMovesMade[0][2] == 1)))
	{
		RenderText("X wins! KONGRA4ULE6ANS!!!");
		SDL_Delay(3000);
		m_enumGameState = QUIT;
	}
	else if(((m_iMovesMade[0][0] == m_iMovesMade[1][1]) &&
				(m_iMovesMade[0][0] == m_iMovesMade[2][2]) &&
				(m_iMovesMade[0][0] == 2)) ||
					((m_iMovesMade[0][2] == m_iMovesMade[1][1]) &&
					(m_iMovesMade[1][1] == m_iMovesMade[2][0]) &&
					(m_iMovesMade[0][2] == 2)))
	{
		RenderText("O wins! KONGRA4ULE6ANS!!!");
		SDL_Delay(3000);
		m_enumGameState = QUIT;
	}

	for(int i = 0; i < BOARD_WIDTH_POSITIONS; i++)
	{
		//win by cols
		if( ((m_iMovesMade[0][i] == m_iMovesMade[1][i]) &&
				(m_iMovesMade[1][i] == m_iMovesMade[2][i]) &&
				m_iMovesMade[0][i] == 1) ||
			//win by rows
			((m_iMovesMade[i][0] == m_iMovesMade[i][1]) &&
			(m_iMovesMade[i][0] == m_iMovesMade[i][2]) &&
			(m_iMovesMade[i][0] == 1)) )
		{
			RenderText("X wins! KONGRA4ULE6ANS!!!");
			SDL_Delay(3000);
			m_enumGameState = QUIT;
		}
		else if( ((m_iMovesMade[0][i] == m_iMovesMade[1][i]) &&
					(m_iMovesMade[1][i] == m_iMovesMade[2][i]) &&
						m_iMovesMade[0][i] == 2 ) ||
				((m_iMovesMade[i][0] == m_iMovesMade[i][1]) &&
						(m_iMovesMade[i][0] == m_iMovesMade[i][2]) &&
						(m_iMovesMade[i][0] == 2)) )
		{
			RenderText("O wins! KONGRA4ULE6ANS!!!");
			SDL_Delay(3000);
			m_enumGameState = QUIT;
		}
	}
}
