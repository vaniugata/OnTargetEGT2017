#include "Button.h"

int main(int args, char* argc[])
{
	Button* button = new Button();

	while(button->m_gameState != QUIT)
	{
		button->Play();
	}

	button->~Button();

	return 0;
}
