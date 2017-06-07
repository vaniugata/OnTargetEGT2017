#include "Texture.h"
#include <SDL2/SDL_image.h>
#include <iostream>
using std::cerr;

SDL_Renderer* Texture::gRenderer = NULL;

Texture::Texture() : m_texture(NULL), m_iWidth(0), m_iHeight(0)
{

}

Texture::~Texture()
{
	Free();
}

int Texture::GetWidth() const
{
	return this->m_iWidth;
}

int Texture::GetHeight() const
{
	return this->m_iHeight;
}

bool Texture::LoadFromFile(std::string path)
{
	Free();
	SDL_Surface* imageSurface = IMG_Load(path.c_str() );
	if(imageSurface == NULL)
	{
		std::cerr << "Failed to load image.";
	}

	SDL_SetColorKey(imageSurface, SDL_TRUE, SDL_MapRGB(imageSurface->format, 255, 255, 255));
	//SDL_SetColorKey(imageSurface, SDL_TRUE, SDL_MapRGB(imageSurface->format, 195, 195, 195));

	SDL_Texture* resultTexture = SDL_CreateTextureFromSurface(gRenderer, imageSurface);
	if(resultTexture == NULL)
	{
		std::cerr << "unable to create texture from image.";
	}

	this->m_iWidth = imageSurface->w;
	this->m_iHeight = imageSurface->h;

	SDL_FreeSurface(imageSurface);

	this->m_texture = resultTexture;

	return this->m_texture != NULL;
}

void Texture::Render(int x, int y,  SDL_Rect* clip)
{
	SDL_Rect renderQuad {x, y, m_iWidth, m_iHeight};

	//set clip rendering dimesion
	if(clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(gRenderer, m_texture, clip, &renderQuad);
}

void Texture::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(m_texture, red, green,blue);
}

void Texture::Free()
{
	if(this->m_texture != NULL)
	{
		SDL_DestroyTexture(this->m_texture);
		this->m_texture = NULL;
		this->m_iWidth = 0;
		this->m_iHeight = 0;
	}
}
