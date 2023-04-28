#ifndef GHOST_OBJECT_H_INCLUDED
#define GHOST_OBJECT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include "constants.h"
#include <math.h>
#include <vector>
#include <utility>
#include "valueToUse.h"

bool inside(int x, int y);

void BFS(int a[18][18], vector<pair<int, int>>& way,
         pair<int, int> start,
         pair<int, int> target);

void moveTo (SDL_Rect &ghost_rect, int v_ghost, int x, int y );

void ghostMove(SDL_Rect &ghost_rect, SDL_Rect &main_rect,
          vector<pair<int, int>>& way, int a[][MAP_WIDTH],
          int v_ghost, int &count );

#endif // GHOST_OBJECT_H_INCLUDED
