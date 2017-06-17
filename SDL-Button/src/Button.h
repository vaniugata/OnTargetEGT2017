#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

#include <SDL2/SDL.h>

typedef enum
{
	PLAY,
	QUIT
} eGameState;

class Button
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Event m_event;
	SDL_Rect m_buttonRect;
public:
	eGameState m_gameState;

	Button();
	virtual ~Button();
	void Play();

private:
	void Init();
	void DrawButton();
	void IncreaseButton();
	bool FitsScreen();
	bool IsMouseOnButton();
};

#endif /* SRC_BUTTON_H_ */
