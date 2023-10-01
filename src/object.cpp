#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "object.hpp"

Object::Object(SDL_Texture* texture, float p_x, float p_y, int p_w, int p_h) {
	x = p_x;
	y = p_y;
	w = p_w;
	h = p_h;

	tex = texture;

	currentFrame.x = x;
	currentFrame.y = y;
	currentFrame.w = w;
	currentFrame.h = h;
}

float Object::getX() {
	return x;
}

float Object::getY() {
	return y;
}

void Object::setX(float p_x) {
	x = p_x;
}

void Object::setY(float p_y) {
	y = p_y;
}

SDL_Texture* Object::getTexture() {
	return tex;
}

SDL_Rect Object::getCurrentFrame() {
	return currentFrame;
}