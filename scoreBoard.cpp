#include "file.header/scoreBoard.h"
#include "file.header/constants.h"
#include <iostream>
using namespace std;

void takeHighScore(int &maxScore, std::string s){
    //lấy highscore từ file
    ifstream infile0(s);
    if (infile0.is_open()) {
        infile0 >> maxScore;
    }
    infile0.close();
}
void recevieScore(int score,int maxScore, std::string s){
    ifstream infile("data/txt/history.txt");
    if (infile.is_open()) {
        infile >> maxScore;
        if (score >= maxScore) {
            infile.close();
            ofstream outfile("data/txt/history.txt");
            if (outfile.is_open()) {
                outfile << score;
                outfile.close();
            }
        }
        else {
            infile.close();
        }
    }
}

void renderScore(SDL_Renderer* renderer, const std::string& fontName, int score, int maxScore) {
    // Load font
    TTF_Font* font = TTF_OpenFont(fontName.c_str(), fontSize);
    if (font == nullptr) {
        cout << "Failed to load font. SDL_ttf Error: " << TTF_GetError() << endl;
        return;
    }

    // Render score
    SDL_Rect scoreRect = { SCREEN_WIDTH - 200, 10, 0, 0 };
    std::string scoreString = "Score: " + std::to_string(score);
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreString.c_str(), color);
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_FreeSurface(scoreSurface);
    SDL_QueryTexture(scoreTexture, nullptr, nullptr, &scoreRect.w, &scoreRect.h);
    SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);
    //SDL_DestroyTexture(scoreTexture);

    // Render max score
    SDL_Rect maxScoreRect = { SCREEN_WIDTH - 200, 50, 0, 0 };
    std::string maxScoreString = "Best: " + std::to_string(maxScore);
    SDL_Surface* maxScoreSurface = TTF_RenderText_Solid(font, maxScoreString.c_str(), color);
    SDL_Texture* maxScoreTexture = SDL_CreateTextureFromSurface(renderer, maxScoreSurface);
    SDL_FreeSurface(maxScoreSurface);
    SDL_QueryTexture(maxScoreTexture, nullptr, nullptr, &maxScoreRect.w, &maxScoreRect.h);
    SDL_RenderCopy(renderer, maxScoreTexture, nullptr, &maxScoreRect);
    //SDL_DestroyTexture(maxScoreTexture);
}
