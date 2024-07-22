#include "Entity.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_texture)
	:position(p_pos), texture(p_texture)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;

}

SDL_Texture* Entity::GetTexture()
{
	return texture;
}

SDL_Rect Entity::GetCurrentFrame()
{
	return currentFrame;
}
