#include "SDL3/SDL.h"

#pragma comment(lib, "SDL3")

int main()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	SDL_Window* MyWindow = SDL_CreateWindow("Sample", 640, 480, SDL_WINDOW_OPENGL);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	bool IsRunning = true;
	SDL_Event MyEvent;
	while (IsRunning)
	{
		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_EVENT_QUIT:
			IsRunning = false;
			break;
		default:
			break;
		}
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}