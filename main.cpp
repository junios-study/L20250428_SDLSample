#include "SDL3/SDL.h"

#pragma comment(lib, "SDL3")

int main()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	SDL_Window* MyWindow = SDL_CreateWindow("Sample", 640, 480, SDL_WINDOW_OPENGL);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	int PlayerX = 100;
	int PlayerY = 100;

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
		case SDL_EVENT_KEY_DOWN:
			if (MyEvent.key.key == SDLK_UP)
			{
				PlayerY--;
			}
			if (MyEvent.key.key == SDLK_DOWN)
			{
				PlayerY++;
			}
			if (MyEvent.key.key == SDLK_LEFT)
			{
				PlayerX--;
			}
			if (MyEvent.key.key == SDLK_RIGHT)
			{
				PlayerX++;
			}
			if (MyEvent.key.key == SDLK_ESCAPE)
			{
				IsRunning = false;
			}

			break;
		default:
			break;
		}

		SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
		SDL_RenderClear(MyRenderer);

		SDL_SetRenderDrawColor(MyRenderer, 255, 0, 0, 0);
		SDL_FRect Player{ (float)PlayerX, (float)PlayerY, 100, 100 };
		SDL_RenderFillRect(MyRenderer, &Player);

		SDL_RenderPresent(MyRenderer);
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}