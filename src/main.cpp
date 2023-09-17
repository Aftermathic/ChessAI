#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "window.hpp"

int main(int argc, char* args[]) {
    std::string startingFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"; // remember to add a underscore for black pieces

    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL_INIT_VIDEO failed.\nError: " << SDL_GetError() << std::endl;
        std::cin.get();

        return -1;
    }

    if ((!IMG_Init(IMG_INIT_PNG))) {
        std::cout << "ING_Init failed.\nError: " << SDL_GetError() << std::endl;
        std::cin.get();

        return -1;
    }

    Window window("Chess A.I", 1280, 720);

    SDL_Texture* chessboard = window.loadTexture("res/spr/chessboard.png");

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        window.clear();
        window.renderTexture(chessboard, 0, 0, 731, 720);
        window.display();
    }

    window.closeWindow();
    SDL_Quit();

    return 0;
}