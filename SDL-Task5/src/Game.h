#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "globals.hpp"

typedef enum
{
	QUIT,
	PLAY

} enumGameState;

struct MousePos {int x; int y; };

class Game
{
public:
	static SDL_Window* m_window;
	static SDL_Renderer* m_renderer;
	static bool m_bBoard[BOARD_WIDTH_POSITIONS][BOARD_HEIGHT_POSITIONS];
	static int m_iMovesMade[BOARD_WIDTH_POSITIONS][BOARD_HEIGHT_POSITIONS];

	enumGameState m_enumGameState;
private:
	SDL_Texture* m_texture;
	SDL_Texture* m_playerTexture;
	TTF_Font* m_font;

public:
	Game();
	virtual ~Game();

	void Init();
	void LoadMedia();
	void RenderText(std::string text);
	void RenderBoard();
	void Play(SDL_Event* e);

private:
	bool SwitchPlayers();
	void PlacePlayer();
	MousePos GetMousePosition();
	void Check();
	void Highlight(int r, int g, int b);
	void RemoveHighlight();
	void CheckWin();
};

#endif /* SRC_GAME_H_ */
