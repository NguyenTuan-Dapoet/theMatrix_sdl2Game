#include"file.header/valueToUse.h"
#include"file.header/init.h"
#include <math.h>


//init variable
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

//handle variable
bool quit = false;

//normal variable
int bando[MAP_WIDTH][MAP_HEIGHT] = {0};
bool eatSound = false; // bien am thanh
bool haveKey = false;
bool openGate = false;
int k = 1;  // biến đếm để xuất hiện 1 cặp gate-key

int score = 0;
int maxScore = 0;

bool pressLeft = false;  //biến bấm nút
bool pressRight = false;
bool pressUp = false;
bool pressDown = false;
int countAnimation = 0; //biến để tạo ảnh động

//texture object
SDL_Texture* wall;
SDL_Texture* point00;
SDL_Texture* point01;
SDL_Texture* key;
SDL_Texture* gate;
SDL_Texture* main_texture;
SDL_Texture* texture_00;
SDL_Texture* texture_01;
SDL_Texture* texture_02;
SDL_Texture* texture_03;

void load_textures(SDL_Renderer* renderer) {
    wall = IMG_LoadTexture(renderer, "data/image/wall.png");
    point00 = IMG_LoadTexture(renderer, "data/image/point00.png");
    point01 = IMG_LoadTexture(renderer, "data/image/point01.png");
    key = IMG_LoadTexture(renderer, "data/image/key.png");
    gate = IMG_LoadTexture(renderer, "data/image/gate.png");

    main_texture = IMG_LoadTexture(renderer, "data/image/mainleft.png");
    texture_00 = IMG_LoadTexture(renderer, "data/image/00.png");
    texture_01 = IMG_LoadTexture(renderer, "data/image/01.png");
    texture_02 = IMG_LoadTexture(renderer, "data/image/02.png");
    texture_03 = IMG_LoadTexture(renderer, "data/image/03.png");
}


//rect object
SDL_Rect loseRect = {50, 200, 550, 250};
SDL_Rect imgPlayRect = {130, 460, 100, 50};
SDL_Rect imgExitRect = {570, 460, 100, 50};
SDL_Rect main_rect = {8 * TILE_SIZE, 9 * TILE_SIZE, TILE_SIZE - 3, TILE_SIZE - 3};
SDL_Rect rect_00 = {2 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE};
SDL_Rect rect_01 = {15 * TILE_SIZE, 1 * TILE_SIZE, TILE_SIZE, TILE_SIZE};
SDL_Rect rect_02 = {2 * TILE_SIZE, 16 * TILE_SIZE, TILE_SIZE, TILE_SIZE};
SDL_Rect rect_03 = {15 * TILE_SIZE, 16 * TILE_SIZE, TILE_SIZE, TILE_SIZE};



//ghost variable

int count_00_way = 0;
int count_01_way = 0;
int count_02_way = 0;
int count_03_way = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> way00;
vector<pair<int, int>> way01;
vector<pair<int, int>> way02;
vector<pair<int, int>> way03;
