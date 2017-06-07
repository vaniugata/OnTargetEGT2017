#ifndef SRC_TEXTURE_H_
#define SRC_TEXTURE_H_

#include <SDL2/SDL.h>
#include <string>

class Texture
{
public:
	//The window renderer
	static SDL_Renderer* gRenderer;
private:
	SDL_Texture* m_texture;
	int m_iWidth;
	int m_iHeight;

public:
	Texture();
	virtual ~Texture();

	//getters
	int GetWidth() const;
	int GetHeight() const;

	bool LoadFromFile(std::string path);
	void Render(int x, int y, SDL_Rect* clip = NULL);
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void Free();

};

#endif /* SRC_TEXTURE_H_ */
