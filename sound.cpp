#include"file.header/sound.h"

void playStart(){
    Mix_Chunk* bg_m = Mix_LoadWAV("data/sound/start.wav");
    Mix_PlayChannel(0, bg_m, 0); // phát nhạc một lần
}

void playEat(){
    Mix_Chunk* eat_m = Mix_LoadWAV("data/sound/eat.wav");
    Mix_PlayChannel(1, eat_m, 0); // phát nhạc một lần
}

void playDead(){
    Mix_Chunk* dead_m = Mix_LoadWAV("data/sound/dead.wav");
    Mix_PlayChannel(2, dead_m, 0); // phát nhạc một lần

}


