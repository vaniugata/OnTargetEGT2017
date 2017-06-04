/*
 * Picture.cpp
 *
 *  Created on: 2.06.2017 ?.
 *      Author: Vaniugata
 */

#include "Picture.h"

Picture::Picture()
{
	// TODO Auto-generated constructor stub

}

Picture::~Picture()
{
	// TODO Auto-generated destructor stub
}

void Picture::setPosition(int x, int y)
{
}

void Picture::handleEvent(SDL_Event* e, SDL_Rect& rect)
{
	if( e->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		if( (x >= rect.x && x <= rect.x + rect.w) &&
				(y >= rect.y && y <= rect.y + rect.h) )
		{
			rect.x = 40;
			rect.y = 40;
		}
	}
}

void Picture::render(SDL_Renderer& renderer, SDL_Texture& texture, SDL_Rect& rect)
{
	SDL_RenderCopy(&renderer, &texture, NULL, &rect);
	SDL_RenderPresent(&renderer);
}
