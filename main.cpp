#include "SDL3/SDL.h"

#pragma comment(lib, "SDL3")

int main()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	SDL_Window* MyWindow = SDL_CreateWindow("Sample", 640, 480, SDL_WINDOW_OPENGL);

	SDL_Delay(3000);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}