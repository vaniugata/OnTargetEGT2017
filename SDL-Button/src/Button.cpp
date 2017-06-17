#include "Button.h"
#include "Globals.hpp"
#include <iostream>
using std::cerr;

Button::Button() : m_window(NULL), m_renderer(NULL), m_event(),	m_gameState(PLAY)
{
	Init();

	m_buttonRect.x = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
	m_buttonRect.y = (SCREEN_HEIGHT - BUTTON_HEIGTH) / 2;
	m_buttonRect.w = BUTTON_WIDTH;
	m_buttonRect.h = BUTTON_HEIGTH;

	DrawButton();
}

Button::~Button()
{
	SDL_DestroyWindow(m_window);
	m_window = NULL;
	SDL_DestroyRenderer(m_renderer);
	m_renderer = NULL;
}

void Button::Play()
{
	while(SDL_PollEvent(&m_event) > 0)
	{
		switch(m_event.type)
		{
		case SDL_QUIT:
			m_gameState = QUIT;
			break;

		case SDL_MOUSEBUTTONDOWN:
			if(FitsScreen() && IsMouseOnButton())
				IncreaseButton();
			break;
		}
	}
}

void Button::Init()
{
	m_window = SDL_CreateWindow("Button", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,\
				SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderPresent(m_renderer);
}

void Button::DrawButton()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, 0);
	SDL_RenderFillRect(m_renderer, &m_buttonRect);
	SDL_RenderPresent(m_renderer);
}

void Button::IncreaseButton()
{
	m_buttonRect.x -= PIXEL_STEP / 2;
	m_buttonRect.y -= PIXEL_STEP / 2;
	m_buttonRect.w += PIXEL_STEP;
	m_buttonRect.h += PIXEL_STEP;

	SDL_RenderDrawRect(m_renderer, &m_buttonRect);
	SDL_RenderPresent(m_renderer);
}

bool Button::FitsScreen()
{
	return m_buttonRect.w <= SCREEN_WIDTH && m_buttonRect.h <= SCREEN_HEIGHT;
}

bool Button::IsMouseOnButton()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	return (x >= m_buttonRect.x && x <= m_buttonRect.x + m_buttonRect.w) && \
			(y >= m_buttonRect.y && y <= m_buttonRect.y + m_buttonRect.h);
}
