#include "file.header/map.h"

void readMatrix(const std::string& filename, int bando[][MAP_WIDTH]) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cout << "Failed to open file." << std::endl;
        return;
    }

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            infile >> bando[i][j];
        }
    }
    infile.close();
}

void render(int bando[][MAP_WIDTH], SDL_Renderer* renderer,
                 SDL_Texture* point00, SDL_Texture* point01, SDL_Texture* wall,
                 SDL_Texture* key, SDL_Texture* gate) {
    SDL_Rect wallRect;
    SDL_Rect itemRect;
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            wallRect = { j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE  , TILE_SIZE };
            itemRect = { j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE  , TILE_SIZE };
            if (bando[i][j] == 0) {
                SDL_RenderCopy(renderer, point00, NULL, &itemRect);
            } else if (bando[i][j] == 1) {
                SDL_RenderCopy(renderer, wall, NULL, &wallRect);
            } else if (bando[i][j] == 2) {
                SDL_RenderCopy(renderer, point01, NULL, &itemRect);
            } else if (bando[i][j] == 7) {
                SDL_RenderCopy(renderer, key, NULL, &itemRect);
            } else if (bando[i][j] == 8) {
                SDL_RenderCopy(renderer, gate, NULL, &itemRect);
            }
        }
    }
}

void getKeyGate(int matrix[MAP_HEIGHT][MAP_WIDTH]) {
    int row1, row2, col1, col2;
    do {
        row1 = rand() % (MAP_WIDTH- 1) + 1;
        col1 = rand() % (MAP_HEIGHT- 1) + 1;
        row2 = rand() % (MAP_WIDTH- 1) + 1;
        col2 = rand() % (MAP_HEIGHT- 1) + 1;
    } while ((abs(row1 - row2) < 10 || abs(col1 - col2) < 10) || (row1 == row2 && col1 == col2) || (matrix[row1][col1] == 1 || matrix[row1][col1] == 3 || matrix[row1][col1] == 4 || matrix[row1][col1] == 5 || matrix[row1][col1] == 6) || (matrix[row2][col2] == 1 || matrix[row2][col2] == 3 || matrix[row2][col2] == 4 || matrix[row2][col2] == 5 || matrix[row2][col2] == 6));
    matrix[row1][col1] = 7;
    matrix[row2][col2] = 8;
}
