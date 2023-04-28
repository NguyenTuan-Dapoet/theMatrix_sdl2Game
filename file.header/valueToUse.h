#ifndef VALUETOUSE_H_INCLUDED
#define VALUETOUSE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include "constants.h"
#include <vector>

using namespace std;

//init variable
extern SDL_Window* window ;
extern SDL_Renderer* renderer;


//handle variable
extern bool quit;


//normal variable
extern int bando[MAP_WIDTH][MAP_HEIGHT];
extern bool eatSound;   // bien am thanh
extern bool haveKey;
extern bool openGate;
extern int k;       // biến đếm để xuất hiện 1 cặp gate-key

extern int score;
extern int maxScore;

extern bool pressLeft;   //biến bấm nút
extern bool pressRight;
extern bool pressUp;
extern bool pressDown;
extern int countAnimation; // bien dem hoat anh


/*=======*/
extern int dx[4];
extern int dy[4];
extern vector<pair<int, int>> way00;
extern vector<pair<int, int>> way01;
extern vector<pair<int, int>> way02;
extern vector<pair<int, int>> way03;

/*=======*/


//texture object
extern SDL_Texture* wall ;
extern SDL_Texture* point00;
extern SDL_Texture* point01;
extern SDL_Texture* key;
extern SDL_Texture* gate;

extern SDL_Texture* main_texture;
extern SDL_Texture* texture_00;
extern SDL_Texture* texture_01;
extern SDL_Texture* texture_02;
extern SDL_Texture* texture_03;

void load_textures(SDL_Renderer* renderer);


//rect object
extern SDL_Rect loseRect;
extern SDL_Rect imgPlayRect;
extern SDL_Rect imgExitRect;

extern SDL_Rect main_rect;
extern SDL_Rect rect_00;
extern SDL_Rect rect_01;
extern SDL_Rect rect_02;
extern SDL_Rect rect_03;


//ghost_reback variable

extern int count_00_way;
extern int count_01_way;
extern int count_02_way;
extern int count_03_way;

extern bool return_x_00;
extern bool return_y_00;

extern bool return_x_01;
extern bool return_y_01;

extern bool return_x_02;
extern bool return_y_02;

extern bool return_x_03;
extern bool return_y_03;

extern float angle_00;  // tính góc giữa đường thẳng đi qua hai điểm so với trục Ox
extern float angle_01;
extern float angle_02;
extern float angle_03;

#endif // VALUETOUSE_H_INCLUDED
