#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
	Entity(float p_x, float p_y, SDL_Texture* p_texture);
	float GetX();
	float GetY();
	SDL_Texture* GetTexture();
	SDL_Rect GetCurrentFrame();
private:
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};