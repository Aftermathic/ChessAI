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

void Window::renderTexture(SDL_Texture* texture, int x, int y, int w, int h) {
	SDL_Rect src = {0, 0, w, h};
	SDL_Rect dst = {x, y, w, h};

	SDL_RenderCopy(renderer, texture, &src, &dst);
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