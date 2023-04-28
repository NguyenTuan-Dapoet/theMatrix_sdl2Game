#include "file.header/screen.h"
#include "file.header/sound.h"
#include "file.header/main_object.h"
#include "file.header/valueToUse.h"

Screen::Screen(SDL_Renderer *renderer) {
    // khởi tạo các biến
    WelcomeTexture = IMG_LoadTexture(renderer, "data/image/Welcome.png");
    imgPlayTexture = IMG_LoadTexture(renderer, "data/image/play.png");
    imgExitTexture = IMG_LoadTexture(renderer, "data/image/exit.png");
    LoseTexture = IMG_LoadTexture(renderer,"data/image/over.png");
}


Screen::~Screen() {
    // giải phóng các biến
}

void Screen::showMenu(SDL_Renderer *renderer, bool& outSystem) {
    SDL_RenderCopy(renderer, WelcomeTexture, NULL, NULL);
    SDL_RenderCopy(renderer, imgPlayTexture, NULL, &imgPlayRect);
    SDL_RenderCopy(renderer, imgExitTexture, NULL, &imgExitRect);

    SDL_RenderPresent(renderer);
    bool temp = false;

    while (!temp) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT){
                temp = true;
                outSystem = true;
            }

            if(event.type == SDL_MOUSEBUTTONDOWN ) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= imgPlayRect.x && x < imgPlayRect.x + imgPlayRect.w && y >= imgPlayRect.y && y < imgPlayRect.y + imgPlayRect.h) {
                    temp = true;
                }
                else if (x >= imgExitRect.x && x < imgExitRect.x + imgExitRect.w && y >= imgExitRect.y && y < imgExitRect.y + imgExitRect.h) {
                    temp = true;
                    outSystem = true;
                }
            }
        }
    }
    //Mix_HaltChannel(0); // tat nhac nen, nhac so 0
    SDL_DestroyTexture(imgPlayTexture);
    SDL_DestroyTexture(imgExitTexture);
    SDL_DestroyTexture(WelcomeTexture);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Screen::showLose(SDL_Renderer *renderer, bool& outSystem,
                      SDL_Rect main_rect, SDL_Rect rect_00,
                      SDL_Rect rect_01, SDL_Rect rect_02, SDL_Rect rect_03) {
    if(die(main_rect, rect_00) == true ||
       die(main_rect, rect_01) == true ||
       die(main_rect, rect_02) == true ||
       die(main_rect, rect_03) == true ) {

        playDead();
        SDL_RenderCopy(renderer, LoseTexture, NULL, &loseRect);
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(LoseTexture);
        SDL_Delay(2000);
        outSystem = true;
    }
}
