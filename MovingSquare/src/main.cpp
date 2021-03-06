//3. На екарана има фигура/спрайт - след клик върху фигурата тя трябва да се движи със стрелките.
//4. Горната задача - когато фигурата стигне до края на екрана тя трябва да спре да се движи в тази посока.
//5. Напишете програма която движи топче по екрана. Когато топчето докосне някои от стените (края на екрана)
//то трябва да отскочи и да смени посоката си.

#include "Game.h"

int main(int args, char* argc[])
{
	Game* game = new Game();

	while(game->m_eGameState != QUIT)
	{
		game->Play();
	}

	delete game;

	return 0;
}
