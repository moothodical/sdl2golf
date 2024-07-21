#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_width, int p_height);
	SDL_Texture* LoadTexture(const char* p_filePath);
	void Cleanup();
	void Clear();
	void Render(Entity& p_entity);
	void Display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

