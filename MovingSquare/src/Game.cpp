#include "Game.h"
#include <SDL2/SDL_image.h>

Game::Game() : m_window(NULL), m_renderer(NULL), m_textureCircle(NULL)
{
	Init();
	LoadMedia();
	m_rectPlayer.x = (SCREEN_WIDTH - PLAYER_WIDTH) / 2;
	m_rectPlayer.y = (SCREEN_HEIGHT - PLAYER_HEIGHT) / 2;
	m_rectPlayer.w = PLAYER_WIDTH;
	m_rectPlayer.h = PLAYER_HEIGHT;

	m_rectCircle.x = (SCREEN_WIDTH - PLAYER_WIDTH) / 3;
	m_rectCircle.y = (SCREEN_HEIGHT - PLAYER_HEIGHT) / 3;
	m_rectCircle.w = PLAYER_WIDTH;
	m_rectCircle.h = PLAYER_HEIGHT;

	m_velocity.x = 0;
	m_velocity.y = 0;
}

Game::~Game()
{
	SDL_DestroyWindow(m_window);
	m_window = NULL;
	SDL_DestroyRenderer(m_renderer);
	m_renderer = NULL;

	SDL_DestroyTexture(m_textureCircle);
	m_textureCircle = NULL;

	SDL_Quit();
}

void Game::Play()
{
	while(SDL_PollEvent(&m_event) > 0)
	{
		switch(m_event.type)
		{
		case SDL_QUIT:
			m_eGameState = QUIT;
			break;
		}
		SetVelocity(&m_event);
	}
	MovePlayer();
	MoveCircle();

	RenderPlayer();
	RenderCircle();

	SDL_RenderPresent(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_renderer);
}

void Game::Init()
{
	m_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderPresent(m_renderer);
}

void Game::LoadMedia()
{
	SDL_Surface* surface = IMG_Load("circle.png");
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 255, 255));
	m_textureCircle = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_FreeSurface(surface);
}

void Game::RenderPlayer()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 255, 120, 255);
	SDL_RenderDrawRect(m_renderer, &m_rectPlayer);
}

void Game::RenderCircle()
{
	SDL_RenderCopy(m_renderer, m_textureCircle, NULL, &m_rectCircle);
}

void Game::SetVelocity(SDL_Event* event)
{
	if(event->type == SDL_KEYDOWN && event->key.repeat == 0)
	{
		switch(event->key.keysym.sym)
		{
		case SDLK_w: case SDLK_UP: 	  m_velocity.y -= VELOCITY; break;
		case SDLK_s: case SDLK_DOWN:  m_velocity.y += VELOCITY; break;
		case SDLK_a: case SDLK_LEFT:  m_velocity.x -= VELOCITY; break;
		case SDLK_d: case SDLK_RIGHT: m_velocity.x += VELOCITY; break;
		}
	}

	else if (event->type == SDL_KEYUP && event->key.repeat == 0)
	{
		switch(event->key.keysym.sym)
		{
		case SDLK_w: case SDLK_UP: 	  m_velocity.y += VELOCITY; break;
		case SDLK_s: case SDLK_DOWN:  m_velocity.y -= VELOCITY; break;
		case SDLK_a: case SDLK_LEFT:  m_velocity.x += VELOCITY; break;
		case SDLK_d: case SDLK_RIGHT: m_velocity.x -= VELOCITY; break;
		}
	}
}

void Game::MovePlayer()
{
	m_rectPlayer.x += m_velocity.x;
	m_rectPlayer.y += m_velocity.y;

	if(m_rectPlayer.x < 0 || (m_rectPlayer.x + m_rectPlayer.w > SCREEN_WIDTH) || \
			CheckCollision(&m_rectPlayer, &m_rectCircle) )
	{
		m_rectPlayer.x -= m_velocity.x;
	}
	else if(m_rectPlayer.y < 0 || (m_rectPlayer.y + m_rectPlayer.h > SCREEN_HEIGHT) || \
			CheckCollision(&m_rectPlayer, &m_rectCircle) )
	{
		m_rectPlayer.y -= m_velocity.y;
	}

}

void Game::MoveCircle()
{
	static bool goLeft = false;
	static bool goDown = false;

	if(m_rectCircle.x < 0 ||  CheckCollision(&m_rectPlayer, &m_rectCircle) )
		goLeft = true;

	if( (m_rectCircle.x + m_rectCircle.w > SCREEN_WIDTH) ||
			CheckCollision(&m_rectPlayer, &m_rectCircle) )
		goLeft = false;

	if(goLeft)
		m_rectCircle.x += VELOCITY;
	else
		m_rectCircle.x -= VELOCITY;

	if(m_rectCircle.y < 0 || CheckCollision(&m_rectPlayer, &m_rectCircle) )
		goDown = true;
	else if ( (m_rectCircle.y + m_rectCircle.h > SCREEN_HEIGHT) || \
			CheckCollision(&m_rectPlayer, &m_rectCircle))
		goDown = false;

	if(goDown)
		m_rectCircle.y += VELOCITY;
	else
		m_rectCircle.y -= VELOCITY;
}

bool Game::IsInside()
{
	if( (m_rectPlayer.x > 0 && \
			m_rectPlayer.x + m_rectPlayer.w < SCREEN_WIDTH) &&\
			(m_rectPlayer.y > 0 && \
					m_rectPlayer.y + m_rectPlayer.h < SCREEN_HEIGHT))
	{
		return true;
	}

	return false;
}

bool Game::CheckCollision(SDL_Rect* a, SDL_Rect* b)
{
	int topA, botA, leftA, rightA;
	int topB, botB, leftB, rightB;

	topA = a->y;
	botA = a->y + a->h;
	leftA = a->x;
	rightA = a->x + a->w;

	topB = b->y;
	botB = b->y + b->h;
	leftB = b->x;
	rightB = b->x + b->w;

	if(botA <= topB )
		return false;

	if(topA >= botB)
		return false;

	if(rightA <= leftB)
		return false;

	if(leftA >= rightB)
		return false;

	return true;
}

