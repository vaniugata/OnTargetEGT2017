#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <SDL2/SDL.h>
#include <vector>
#include <map>

#include "globals.hpp"

typedef enum
{
	PLAY,
	QUIT,
}eGameState;

class Game
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_backgroundTexture;
	SDL_Texture* m_figuresTexture;
	SDL_Event m_e;

	std::map<std::string, SDL_Rect> m_mapFiguresTextures;
	std::vector<SDL_Rect> m_vecFromTexture;
	SDL_Rect m_arrOnScreen[BOARD_X_POSITIONS][BOARD_Y_POSITIONS];

public:
	eGameState m_eGameState;

public:
	Game();
	virtual ~Game();

private:
	void Init();
	void LoadMedia();
	void Free();
	void ShowMouseCoords();
	void RenderChessFigures();
public:
	void Play();
	void RenderGameBoard();
	void RenderScreenMatrix();
	void CopyFiguresToMap();
};

#endif /* SRC_GAME_H_ */
