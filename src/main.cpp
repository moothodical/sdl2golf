#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char* args[]) 
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "sdl init has failed: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init has failed: " << SDL_GetError() << std::endl;

	RenderWindow window("game", 1280, 720);
	SDL_Texture* grassTexture = window.LoadTexture("res/gfx/ground_grass_1.png");

	Entity platform(100, 100, grassTexture);

	bool gameRunning = true;

	SDL_Event event;

	// game loop
	while (gameRunning)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.Clear();
		window.Render(platform);
		window.Display();
	}

	window.Cleanup();
	SDL_Quit();
	return 0;
}