#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <fstream>
#include <iostream>
#include "constants.h"
#include "init.h"

void readMatrix(const std::string& filename, int bando[][MAP_WIDTH]);

void render(int bando[][MAP_WIDTH], SDL_Renderer* renderer,
                 SDL_Texture* point00, SDL_Texture* point01, SDL_Texture* wall,
                 SDL_Texture* key, SDL_Texture* gate);

void getKeyGate(int matrix[MAP_HEIGHT][MAP_WIDTH]);
#endif // MAP_H_INCLUDED
