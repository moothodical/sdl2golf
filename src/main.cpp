#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

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

	std::vector<Entity> entities = {Entity(0, 0, grassTexture),
									 Entity(0, 32, grassTexture),
									 Entity(0, 64, grassTexture),
									 Entity(0, 96, grassTexture)};

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

		for (Entity& e : entities)
		{
			window.Render(e);
		}

		window.Display();
	}

	window.Cleanup();
	SDL_Quit();
	return 0;
}