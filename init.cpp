#include "file.header/init.h"
#include "file.header/constants.h"

void init_SDL(SDL_Window*& window, SDL_Renderer*& renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    //tạo cửa sổ
    window = SDL_CreateWindow("NO TIME TO RUN !!!",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    //tạo renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void quit_SDL() {
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
