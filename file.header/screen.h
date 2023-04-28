#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

class Screen {
public:
    Screen(SDL_Renderer *renderer);
    ~Screen();
    void showMenu(SDL_Renderer *renderer, bool& outSystem);
    void showLose(SDL_Renderer *renderer, bool& outSystem,
                      SDL_Rect main_rect, SDL_Rect rect_00,
                      SDL_Rect rect_01, SDL_Rect rect_02, SDL_Rect rect_03);
private:
    SDL_Texture* WelcomeTexture;
    SDL_Texture* LoseTexture;
    SDL_Texture* imgPlayTexture;
    SDL_Texture* imgExitTexture;
};


#endif // SCREEN_H_INCLUDED
