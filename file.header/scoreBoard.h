#ifndef SCOREBOARD_H_INCLUDED
#define SCOREBOARD_H_INCLUDED

#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_ttf.h>

void takeHighScore(int &maxScore, std::string s);
void recevieScore(int score,int maxScore, std::string s);
void renderScore(SDL_Renderer* renderer, const std::string& fontName, int score, int maxScore);


#endif // SCOREBOARD_H_INCLUDED
