#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "window.hpp"
#include "object.hpp"

int main(int argc, char* args[]) {
    std::string startingFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

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

    SDL_Texture* chessboardTexture = window.loadTexture("res/spr/chessboard.png");
    Object chessboard = Object(chessboardTexture, 0, 0, 731, 731);

    // Black Pieces
    SDL_Texture* r = window.loadTexture("res/spr/chesspieces/r_.png");
    SDL_Texture* n = window.loadTexture("res/spr/chesspieces/n_.png");
    SDL_Texture* b = window.loadTexture("res/spr/chesspieces/b_.png");
    SDL_Texture* k = window.loadTexture("res/spr/chesspieces/k_.png");
    SDL_Texture* q = window.loadTexture("res/spr/chesspieces/q_.png");
    SDL_Texture* p = window.loadTexture("res/spr/chesspieces/p_.png");

    // White Pieces
    SDL_Texture* R = window.loadTexture("res/spr/chesspieces/R.png");
    SDL_Texture* N = window.loadTexture("res/spr/chesspieces/N.png");
    SDL_Texture* B = window.loadTexture("res/spr/chesspieces/B.png");
    SDL_Texture* K = window.loadTexture("res/spr/chesspieces/K.png");
    SDL_Texture* Q = window.loadTexture("res/spr/chesspieces/Q.png");
    SDL_Texture* P = window.loadTexture("res/spr/chesspieces/P.png");

    SDL_Texture* nothing = window.loadTexture("res/spr/chesspieces/Nothing.png");

    // ima use this for rendering pieces from FEN
    std::map<char, SDL_Texture*> pieceDictionary = {
        {'r', r},
        {'n', n},
        {'b', b},
        {'k', k},
        {'q', q},
        {'p', p},

        {'R', R},
        {'N', N},
        {'B', B},
        {'K', K},
        {'Q', Q},
        {'P', P}
    };

    std::vector<std::vector<Object>> pieces = {};

    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char backslash = '/';

    int counter = 0;
    int counter2 = 0;

    std::vector<Object> piecesPlaceholder = {};
    while (counter < 63) {
        char character = startingFEN[counter2];
        bool is_number = false;

        for (int& i : numbers) {
            int test = (int) character - 48;

            if (test == i) {
                is_number = true;
                break;
            }
        }

        if (is_number) {
            for (int i = 0; i < (int) character - 48; i++) {
                piecesPlaceholder.push_back(Object(nothing, 0, 0, 91, 91));
                counter++;
            }
        }
        else {
            if (character == backslash) {
                pieces.push_back(piecesPlaceholder);
                piecesPlaceholder.clear();
            }
            else {
                piecesPlaceholder.push_back(Object(pieceDictionary[character], 0, 0, 91, 91));
            }
        }

        counter2++;
    }

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        window.clear();
        window.renderObject(chessboard);

        for (auto& t : pieces) {
            for (auto& piece : t) {
                window.renderObject(piece);
            }
        }

        window.display();
    }

    window.closeWindow();
    SDL_Quit();

    return 0;
}