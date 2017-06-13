#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include <vector>

#include "globals.hpp"

class Game
{
public:
	static SDL_Renderer* m_renderer;
	static SDL_Window* m_window;

private:
	SDL_Texture* m_texture;
	TTF_Font* m_font;
	SDL_Texture* m_fontTexture;
	std::vector<SDL_Rect> m_vecSprites;
	std::vector<SDL_Rect> m_vecCardsOnScreen;

public:
	Game();
	virtual ~Game();

	void Init();
	void Render(SDL_Rect& from, SDL_Rect& to);
	void LoadFromFile(std::string fileName);
	void Free();

	void RenderStart();
	void RenderCards();
	void FlipCard();
	void DeleteCard();
	int CardIndex();

	//helpers
	void ShowMouseCoords();
	void ViewRects();

};

#endif /* SRC_GAME_H_ */
