#include "Rectangle.h"
#include "Globals.h"
#include <stdlib.h>
#include <time.h>

Rectangle::Rectangle()
{
	GenerateRandomRect();
}

Rectangle::~Rectangle()
{

}



void Rectangle::Draw(SDL_Renderer* renderer)
{
	SetRandomDrawColor(renderer);
	SDL_RenderFillRect(renderer, &m_rect);
	SDL_RenderPresent(renderer);
}

void Rectangle::Clear()
{

}

void Rectangle::GenerateRandomRect()
{
	m_rect.x = rand() % SCREEN_WIDTH + 1;
	m_rect.y = rand() % SCREEN_HEIGHT + 1;

	m_rect.w = rand() % SCREEN_WIDTH / 2;
	m_rect.h = rand() % SCREEN_HEIGHT / 2;
}


void Rectangle::SetRandomDrawColor(SDL_Renderer* renderer)
{
	int r, g, b;
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;

	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}
