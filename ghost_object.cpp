#include "file.header/ghost_object.h"
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool inside(int x, int y) {
    return (0 <= x && x < MAP_WIDTH && 0 <= y && y < MAP_HEIGHT);
}

void BFS(int a[18][18], vector<pair<int, int>>& way,
         pair<int, int> start,
         pair<int, int> target){

    int miniWay[20][20] = {};
    pair<int, int> trace[20][20] = {};
    queue<pair<int, int>> q;
    trace[start.first][start.second] = { start.first, start.second };
    miniWay[start.first][start.second] = 1;
    q.push(start);
    while (q.size()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        if (u == target.first && v == target.second) break;
        for (int i = 0; i < 4; i++){

            int x = u + dx[i];
            int y = v + dy[i];

            if (inside(x, y) && !miniWay[x][y] && a[x][y] != 1){
                miniWay[x][y] = miniWay[u][v] + 1;
                //cout<<x<<' '<<y<<' '<<u<<' '<<v<<endl;
                trace[x][y] = { u, v };
                q.push({ x, y });
            }
        }
    }
    stack<pair<int, int>> road;
    int u = target.first, v = target.second;
        //cout<<miniWay[u][v]<<endl;
    if (!miniWay[u][v]) return;
    road.push({ u, v });
    while (u != start.first || v != start.second){
        int u1 = u;
        u = trace[u][v].first;
        v = trace[u1][v].second;
        //cout<<u<<' '<<v<<endl;
        road.push({ u, v });
    }
    while (!road.empty()){
        way.push_back(road.top());
        road.pop();
    }

    /*---change way---*/

    vector<pair<int, int>> new_way;
    new_way.push_back(way[0]);
    int N = way.size();

    for (int i = 2; i < N; ++i){
        if (way[i].first == way[i - 1].first && way[i].first == way[i - 2].first){
            continue;
        }

        else if (way[i].second == way[i - 1].second && way[i].second == way[i - 2].second){
            continue;
        }

        else{
            new_way.push_back(way[i - 1]);
        }
    }
    new_way.push_back(way[N - 1]);

    for(auto& p : new_way) {
        swap(p.first, p.second); // đảo giá trị first và second của mỗi phần tử trong vector new_way
    }
    way = new_way;
}

void moveTo(SDL_Rect &ghost_rect, int v_ghost,
            int x, int y) {

    if(ghost_rect.x == x && ghost_rect.y == y) {
        return;
    }

    if (ghost_rect.x < x) {
        ghost_rect.x += v_ghost;
    } else if (ghost_rect.x > x) {
        ghost_rect.x -= v_ghost;
    }
    if (ghost_rect.y < y) {
        ghost_rect.y += v_ghost;
    } else if (ghost_rect.y > y) {
        ghost_rect.y -= v_ghost;
    }

}

void ghostMove(SDL_Rect &ghost_rect, SDL_Rect &main_rect,
          vector<pair<int, int>>& way, int a[][MAP_WIDTH],
          int v_ghost, int &count ){

   if(ghost_rect.x == way.back().first * TILE_SIZE && ghost_rect.y == way.back().second * TILE_SIZE){
            count = 0;
            way.clear();
            BFS(bando, way,
                {ghost_rect.y / TILE_SIZE, ghost_rect.x / TILE_SIZE},
                {main_rect.y / TILE_SIZE, main_rect.x / TILE_SIZE} );
    }

    else if(ghost_rect.x != way.back().first * TILE_SIZE || ghost_rect.y != way.back().second * TILE_SIZE){
        moveTo(ghost_rect, v_ghost, way[count].first * TILE_SIZE, way[count].second * TILE_SIZE);
        if (ghost_rect.x == way[count].first * TILE_SIZE && ghost_rect.y == way[count].second * TILE_SIZE && static_cast<int>(count) < static_cast<int>(way.size()-1) ) {
            ++count;
        }
    }

    if ( a[ghost_rect.y / TILE_SIZE][ghost_rect.x /TILE_SIZE] == 2){
        a[ghost_rect.y / TILE_SIZE][ghost_rect.x /TILE_SIZE] = 0;
    }
}
