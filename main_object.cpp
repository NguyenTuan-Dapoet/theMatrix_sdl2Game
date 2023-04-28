#include "file.header/main_object.h"

void animation(SDL_Texture*& main_texture, SDL_Renderer* renderer,int& count,
                 const std::string& path0,
                 const std::string& path1,
                 const std::string& path2 ) {
    count += 1;
    int val = count % 15;
    if (val >= 11 && val <= 14) {
        SDL_DestroyTexture(main_texture);
        main_texture = IMG_LoadTexture(renderer, path2.c_str());
    } else if (val == 0) {
        SDL_DestroyTexture(main_texture);
        main_texture = IMG_LoadTexture(renderer, path2.c_str());
        count = 0;
    } else if (val >= 6 && val <= 10) {
        SDL_DestroyTexture(main_texture);
        main_texture = IMG_LoadTexture(renderer, path1.c_str());
    } else if (val >= 1 && val <= 5) {
        SDL_DestroyTexture(main_texture);
        main_texture = IMG_LoadTexture(renderer, path0.c_str());
    }
}

bool move_left(int size_pixel, int x, int y,int w, int step, int boolen[MAP_HEIGHT][MAP_WIDTH]) {
    // Kiểm tra tất cả các ô bên trái của nhân vật main
    for (int i = y; i <= (y+w); i++) {
        if (boolen[i/size_pixel][(x - step)/size_pixel] == 1) {
            return false;
        }
    }
    return true;
}

bool move_right(int size_pixel, int x, int y,int h, int step, int boolen[MAP_HEIGHT][MAP_WIDTH]) {
    // Kiểm tra tất cả các ô bên phai của nhân vật main
    for (int i = y; i <= (y+h); i++) {
        if (boolen[i/size_pixel][(x + h+ step)/size_pixel] == 1) {
            return false;
        }
    }
    return true;
}

bool move_up(int size_pixel, int x, int y,int h, int step, int boolen[MAP_HEIGHT][MAP_WIDTH]) {
    // Kiểm tra tất cả các ô bên tren của nhân vật main
    for (int i = x; i <= (x+h); i++) {
        if (boolen[(y-step)/size_pixel ][(i)/size_pixel] == 1) {
            return false;
        }
    }
    return true;
}

bool move_down(int size_pixel, int x, int y,int h,int w, int step, int boolen[MAP_HEIGHT][MAP_WIDTH]) {
    // Kiểm tra tất cả các ô bên duoi của nhân vật main
    for (int i = x ; i <= x + h ; i++) {
        if (boolen[(y + w + step)/size_pixel][(i)/size_pixel] == 1) {
            return false;
        }
    }
    return true;
}

void pointed(int boolen[MAP_HEIGHT][MAP_WIDTH],bool &eatSound, SDL_Rect main_rect , int &score, bool &haveKey, bool &openGate) {
    for (int j = 0; j < MAP_HEIGHT; j++) {
        for (int i = 0; i < MAP_WIDTH; i++) {
            if (boolen[j][i] == 0) { // Nếu là điểm point
                int pointCenterX = i * TILE_SIZE + TILE_SIZE / 2; // Tính tâm của điểm theo trục x
                int pointCenterY = j * TILE_SIZE + TILE_SIZE / 2; // Tính tâm của điểm theo trục y

                // Kiểm tra va chạm giữa nhân vật main và điểm point
                if (main_rect.x < pointCenterX  && pointCenterX < main_rect.x + main_rect.w &&
                    main_rect.y < pointCenterY  && pointCenterY < main_rect.y + main_rect.h) {

                        score++;
                        boolen[j][i] = 2 ;
                        eatSound = true;
                }
            }
            if (boolen[j][i] == 7) { // Nếu là điểm point
                int pointCenterX = i * TILE_SIZE + TILE_SIZE / 2; // Tính tâm của điểm theo trục x
                int pointCenterY = j * TILE_SIZE + TILE_SIZE / 2; // Tính tâm của điểm theo trục y

                // Kiểm tra va chạm giữa nhân vật main và điểm point
                if (main_rect.x < pointCenterX  && pointCenterX < main_rect.x + main_rect.w &&
                    main_rect.y < pointCenterY  && pointCenterY < main_rect.y + main_rect.h) {

                    haveKey = true;
                    boolen[j][i] = 2 ;
                    eatSound = true;
                }
            }
            if (boolen[j][i] == 8 && haveKey == true ) { // Nếu là điểm point
                int pointCenterX = i * TILE_SIZE + TILE_SIZE / 2; // Tính tâm của điểm theo trục x
                int pointCenterY = j * TILE_SIZE + TILE_SIZE / 2; // Tính tâm của điểm theo trục y

                // Kiểm tra va chạm giữa nhân vật main và điểm point
                if (main_rect.x < pointCenterX + 17 && main_rect.x + 9 > pointCenterX - 17 &&
                    main_rect.y < pointCenterY + 17 &&  main_rect.y + 9 > pointCenterY - 17) {

                    openGate = true;
                }
            }
        }
    }
}

bool die(SDL_Rect main_rect, SDL_Rect ghost_rect) {
    // bởi vì kiểm tra check trong khi bấm nút
    // => tại ra bug ko chết -> tính năng ẩn thân
    // kiểm tra 4 góc cỉa main có va chạm với ghost không
    if (
        (ghost_rect.x < main_rect.x  && main_rect.x < ghost_rect.x + ghost_rect.w &&
        ghost_rect.y < main_rect.y  && main_rect.y < ghost_rect.y + ghost_rect.h) ||
        (ghost_rect.x < main_rect.x + main_rect.w  && main_rect.x + main_rect.w < ghost_rect.x + ghost_rect.w &&
        ghost_rect.y < main_rect.y + main_rect.h  && main_rect.y + main_rect.h < ghost_rect.y + ghost_rect.h) ||
        (ghost_rect.x < main_rect.x + main_rect.w  && main_rect.x + main_rect.w < ghost_rect.x + ghost_rect.w &&
        ghost_rect.y < main_rect.y   && main_rect.y  < ghost_rect.y + ghost_rect.h) ||
        (ghost_rect.x < main_rect.x  && main_rect.x  < ghost_rect.x + ghost_rect.w &&
        ghost_rect.y < main_rect.y + main_rect.h  && main_rect.y + main_rect.h < ghost_rect.y + ghost_rect.h)

       )
    {

        return true;
    }
    return false;
}
