#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texture)
	:x(p_x), y(p_y), texture(p_texture)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;

}

float Entity::GetX()
{
	return x;
}

float Entity::GetY()
{
	return y;
}

SDL_Texture* Entity::GetTexture()
{
	return texture;
}

SDL_Rect Entity::GetCurrentFrame()
{
	return currentFrame;
}
