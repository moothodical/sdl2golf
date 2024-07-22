#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_texture);
	Vector2f& GetPosition()
	{
		return position;
	}
	SDL_Texture* GetTexture();
	SDL_Rect GetCurrentFrame();
private:
	Vector2f position;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};