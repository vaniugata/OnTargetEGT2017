#ifndef SRC_TEXTURE_H_
#define SRC_TEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>

const int SCREEN_WIDTH = 1324;
const int SCREEN_HEIGHT = 512;

class Texture
{
private:
	const int SPRITE_WIDTH = 100;
	const int SPRITE_HEIGHT = 100;
	const int NUMBER_OF_SPRITES = 5;

	const int PIXEL_STEP = 20;

	SDL_Texture* m_texture;
	SDL_Texture* m_coordsTexture;

public:
	static SDL_Renderer* m_Renderer;
	static TTF_Font* m_Font;

	std::vector<SDL_Rect> m_vecSprites;

	Texture();
	virtual ~Texture();

	//getters
	SDL_Texture& getTexture() const;

	bool LoadFromFile(std::string path);
	bool LoadFromRenderedText( int x, int y);
	bool Render();
	void Free();
};

#endif /* SRC_TEXTURE_H_ */
