#include "Texture.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
using std::cerr;
#include <sstream>

 SDL_Renderer* Texture::m_Renderer = nullptr;
 TTF_Font* Texture::m_Font = nullptr;

Texture::Texture() : m_texture(nullptr)
{

}

Texture::~Texture()
{
}

SDL_Texture& Texture::getTexture() const
{
	return *m_texture;
}

bool Texture::LoadFromFile(std::string path)
{
	Free();

	SDL_Surface* imageSurface = IMG_Load(path.c_str() );

	m_texture = SDL_CreateTextureFromSurface(m_Renderer, imageSurface);

	SDL_FreeSurface(imageSurface);

	return true;
}

bool Texture::LoadFromRenderedText(int x, int y)
{
	TTF_Font* font = TTF_OpenFont("lazy.ttf", 28);
	if(font == nullptr)
	{
		std::cerr << "Failed to load font." << SDL_GetError();
	}

	SDL_Color color = {255, 0, 0, 255};
	SDL_Rect textRect {SCREEN_HEIGHT / 2, SCREEN_HEIGHT / 2, 200, 50};

	std::stringstream coords;
	coords << "x: " <<  x << " y: " << y;
	SDL_Surface* surfaceText = TTF_RenderText_Solid(font, coords.str().c_str(), color);
	m_coordsTexture = SDL_CreateTextureFromSurface(Texture::m_Renderer, surfaceText);
	SDL_FreeSurface(surfaceText);
	SDL_RenderCopy(Texture::m_Renderer, m_coordsTexture, NULL, &textRect);

	return true;
}

bool Texture::Render()
{
	for(int i = 0; i < NUMBER_OF_SPRITES; i++)
	{
		SDL_Rect sprite;
		sprite.x = SPRITE_WIDTH * i;
		sprite.y = 0;
		sprite.w = SPRITE_WIDTH;
		sprite.h = SPRITE_HEIGHT;

		m_vecSprites.push_back(sprite);
	}

	for(int i = 0; i < NUMBER_OF_SPRITES; i++)
	{
		SDL_Rect rect;
		rect.x = PIXEL_STEP + (2 * SPRITE_WIDTH * i);
		rect.y = PIXEL_STEP;
		rect.w = SPRITE_WIDTH * 1.5;
		rect.h = SPRITE_HEIGHT * 1.5;

		SDL_RenderCopy(Texture::m_Renderer, m_texture, &m_vecSprites[i], &rect);
	}

	return true;
}

void Texture::Free()
{
	if(m_texture != NULL)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
	}
}
