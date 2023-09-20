#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>

#include "window.hpp"

Window::Window(const char* windowCaption, int window_w, int window_h) {
	window = NULL;
	renderer = NULL;

	window = SDL_CreateWindow(windowCaption,  SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, window_w, window_h, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		std::cout << "Window has failed to initalize.\nError: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	windowSurface = SDL_GetWindowSurface(window);
}

SDL_Texture* Window::loadTexture(const char* filePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL) {
		std::cout << "Failed to load texture.\nError: " << SDL_GetError() << std::endl;
	}

	return texture;
}

void Window::clear() {
	SDL_RenderClear(renderer);
}

void Window::renderObject(Object& object) {
	SDL_Rect src; 
	src.x = object.getCurrentFrame().x;
	src.y = object.getCurrentFrame().y;
	src.w = object.getCurrentFrame().w;
	src.h = object.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = object.getX();
	dst.y = object.getY();
	dst.w = object.getCurrentFrame().w;
	dst.h = object.getCurrentFrame().h;

	SDL_RenderCopy(renderer, object.getTexture(), &src, &dst);
}

void Window::display() {
	SDL_RenderPresent(renderer);
}

// void Window::createRect(int rectX, int rectY, int rectW, int rectH) {
// 	SDL_Rect rect = {rectX, rectY, rectW, rectH};
// 	int SDL_RenderDrawRect(renderer, rect);
// }

void Window::closeWindow() {
	SDL_DestroyWindow(window);
}