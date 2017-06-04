#ifndef SRC_PICTURE_H_
#define SRC_PICTURE_H_

#include <SDL2/SDL.h>

class Picture
{
public:
	//Initializes internal variables
	Picture();
	~Picture();

	//Sets top left position
	void setPosition( int x, int y );

	//Handles mouse event
	void handleEvent( SDL_Event* e , SDL_Rect& rect);

	//Shows button sprite
	void render(SDL_Renderer& renderer, SDL_Texture& texture, SDL_Rect& rect);

private:
	//Top left position
	SDL_Point mPosition;

};

#endif /* SRC_PICTURE_H_ */
