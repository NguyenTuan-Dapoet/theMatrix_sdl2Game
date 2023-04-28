#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>


void init_SDL(SDL_Window*& window, SDL_Renderer*& renderer);
void quit_SDL();

#endif // INIT_H_INCLUDED
