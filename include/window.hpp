#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "object.hpp"

class Window {
	public:
		Window(const char* windowCaption, int window_w, int window_h);
		void closeWindow();

		SDL_Texture* loadTexture(const char* filePath);
		void clear();
		void renderObject(Object& object);
		void display();

		//void createRect(int rectX, int rectY, int rectW, int rectH);

	private:
		SDL_Window* window;
		SDL_Surface* windowSurface;
		SDL_Renderer* renderer;
};