#include "Texture.h"
#include <SDL2/SDL_image.h>


 SDL_Renderer* Texture::m_Renderer = NULL;

Texture::Texture() : m_texture(NULL)
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

	for(int i = 0; i < (int) m_vecSprites.size(); i++)
	{
		SDL_Rect rect;
		rect.x = (PIXEL_STEP + SPRITE_WIDTH) * i * 2;
		rect.y = 0;
		rect.w = SPRITE_WIDTH * 2;
		rect.h = SPRITE_HEIGHT * 2;

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
