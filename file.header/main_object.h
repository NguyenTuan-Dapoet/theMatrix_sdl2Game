#ifndef MAIN_OBJECT_H_INCLUDED
#define MAIN_OBJECT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "constants.h"

//void init_main_texture(SDL_Renderer* renderer);

void animation(SDL_Texture*& main_texture, SDL_Renderer* renderer,int& count,
             const std::string& path0,
             const std::string& path1,
             const std::string& path2 );

bool move_left(int size_pixel, int x, int y,int w, int step, int boolen[MAP_HEIGHT][MAP_WIDTH]);

bool move_right(int size_pixel, int x, int y,int h, int step, int boolen[MAP_HEIGHT][MAP_WIDTH]);

bool move_up(int size_pixel, int x, int y,int h, int step, int boolen[MAP_HEIGHT][MAP_WIDTH] );

bool move_down(int size_pixel, int x, int y,int h,int w, int step, int boolen[MAP_HEIGHT][MAP_WIDTH]);

void pointed(int boolen[MAP_HEIGHT][MAP_WIDTH],bool &eatSound, SDL_Rect main_rect , int &score, bool &haveKey, bool &openGate);

bool die(SDL_Rect main_rect, SDL_Rect ghost_rect);


#endif // MAIN_OBJECT_H_INCLUDED
