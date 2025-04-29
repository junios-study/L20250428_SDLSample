#include "SDL3/SDL.h"

#pragma comment(lib, "SDL3")

int main()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	SDL_Window* MyWindow = SDL_CreateWindow("Sample", 640, 480, SDL_WINDOW_OPENGL);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	float PlayerX = 100;
	float PlayerY = 100;

	bool IsRunning = true;
	SDL_Event MyEvent;

	int NumKeys = 0;
	const bool* KeyStates = SDL_GetKeyboardState(&NumKeys);

	Uint64 CurrentTime = SDL_GetTicks();
	Uint64 LastTime = SDL_GetTicks();
	float DeltaSeconds = 0;
	while (IsRunning)
	{
		CurrentTime = SDL_GetTicks();

		DeltaSeconds = (float)(CurrentTime - LastTime) / 1000.f;

		LastTime = CurrentTime;

		//SDL_Log("%4f\n", DeltaSeconds);

		SDL_PollEvent(&MyEvent);
		switch (MyEvent.type)
		{
		case SDL_EVENT_QUIT:
			IsRunning = false;
			break;
		case SDL_EVENT_KEY_DOWN:
			if (KeyStates[SDL_SCANCODE_UP])
			{
				PlayerY -= 10;
			}
			if (KeyStates[SDL_SCANCODE_DOWN])
			{
				PlayerY += 10;
			}
			if (KeyStates[SDL_SCANCODE_LEFT])
			{
				PlayerX -= 10;
			}
			if (KeyStates[SDL_SCANCODE_RIGHT])
			{
				PlayerX += 10;
			}
			if (KeyStates[SDL_SCANCODE_ESCAPE])
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