#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <SDL2/SDL.h>
#include "Globals.hpp"

struct Velocity
{
	int x;
	int y;
};

typedef enum
{
	PLAY,
	QUIT
} eGameState;

class Game
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_textureCircle;
	SDL_Rect m_rectPlayer;
	SDL_Rect m_rectCircle;
	SDL_Event m_event;
	Velocity m_velocity;

public:
	eGameState m_eGameState;

	Game();
	virtual ~Game();
	void Play();

private:
	void Init();
	void LoadMedia();
	void RenderPlayer();
	void RenderCircle();
	void SetVelocity(SDL_Event*);
	void MovePlayer();
	void MoveCircle();
	bool IsInside();
};

#endif /* SRC_GAME_H_ */
