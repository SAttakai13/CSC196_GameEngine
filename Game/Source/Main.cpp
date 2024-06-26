#include <SDL.h>
#include <stdlib.h>
#include <iostream>


int main(int argc, char* argv[])
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	// create window
	// returns pointer to window if successful or nullptr if failed
	SDL_Window* window = SDL_CreateWindow("Game Engine",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	// create renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	while (true)
	{
		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		// draw line
		//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for (int i = 0; i < 1000; i++)
			SDL_RenderDrawLine(renderer, 0, 0, rand()%800, rand()%600);
			SDL_RenderDrawPoint(renderer, 400, 300);
			//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 0);



		// show screen
		SDL_RenderPresent(renderer);
	}

	return 0;
}