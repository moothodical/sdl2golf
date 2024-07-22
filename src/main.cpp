#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"


int main(int argc, char* args[]) 
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "sdl init has failed: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init has failed: " << SDL_GetError() << std::endl;

	RenderWindow window("game", 1280, 720);
	std::cout << window.GetRefreshRate() << std::endl;
	SDL_Texture* grassTexture = window.LoadTexture("res/gfx/ground_grass_1.png");

	std::vector<Entity> entities = {Entity(Vector2f(0, 0), grassTexture),
									 Entity(Vector2f(0, 32), grassTexture),
									 Entity(Vector2f(0, 64), grassTexture),
									 Entity(Vector2f(0, 96), grassTexture)};

	bool gameRunning = true;

	SDL_Event event;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::HireTimeInSeconds();

	// game loop
	while (gameRunning)
	{
		int startTicks = SDL_GetTicks();
		float newTime = utils::HireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= timeStep)
		{
			// get controls and events
			while(SDL_PollEvent(&event))
			{
				if(event.type == SDL_QUIT)
					gameRunning = false;
			}
			accumulator -= timeStep;
		}

		const float alpha = accumulator / timeStep;

		window.Clear();

		for (Entity& e : entities)
		{
			window.Render(e);
		}

		window.Display();
		int frameTicks = SDL_GetTicks() - startTicks;
		int minimum = 1000 / window.GetRefreshRate();
		if (frameTicks < minimum)
			SDL_Delay(minimum -	frameTicks);
	}

	window.Cleanup();
	SDL_Quit();
	return 0;
}