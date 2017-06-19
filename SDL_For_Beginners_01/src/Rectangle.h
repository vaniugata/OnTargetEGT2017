#ifndef SRC_RECTANGLE_H_
#define SRC_RECTANGLE_H_

#include <SDL2/SDL.h>
class Rectangle
{
private:
	SDL_Rect m_rect;
public:
	Rectangle();
	virtual ~Rectangle();

	void Init();
	void Draw(SDL_Renderer* renderer);
	void Clear();

private:
	void SetRandomDrawColor(SDL_Renderer* renderer);
	void GenerateRandomRect();
};

#endif /* SRC_RECTANGLE_H_ */
