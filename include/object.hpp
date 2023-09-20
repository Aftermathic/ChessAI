#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Object
{
	public:
		Object(SDL_Texture* texture, float p_x, float p_y, int p_w, int p_h);

		float getX();
		float getY();
		SDL_Texture* getTexture(); // to render it on screen
		SDL_Rect getCurrentFrame(); // can be used for animations

	private:
		float x, y;
		int w, h;

		SDL_Rect currentFrame;
		SDL_Texture* tex;
};