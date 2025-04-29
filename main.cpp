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

		SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
		SDL_RenderClear(MyRenderer);


		for (int i = 0; i < 1000; ++i)
		{
			SDL_SetRenderDrawColor(MyRenderer,
				SDL_rand(255),
				SDL_rand(255),
				SDL_rand(255),
				0);
			SDL_FRect MyRect{ SDL_randf() * 640 - 320,
				SDL_randf() * 480 - 240,
				SDL_randf() * 640, SDL_randf() * 480
			};
			SDL_RenderFillRect(MyRenderer, &MyRect);
		}

		SDL_RenderPresent(MyRenderer);
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}