#include<bits/stdc++.h>
using namespace std;
const int MAXN = 30;
const int MAXM = 30;
const int INF = 0x3fffffff;
char grids[MAXN][MAXM];
int startX, startY;
int endX, endY;
int dirX[] = {0, 0, 1, -1};
int dirY[] = {-1, 1, 0, 0};
int n, m;
struct State{
    State(int x = 0, int y = 0):posX(x), posY(y), step(0) {
        memset(visited, false, sizeof(visited));
        visited[x][y] = true;
    }
    int step;
    int posX, posY;
    bool visited[MAXN][MAXM];
};
bool legalPos(int x, int y) {
    return x >= 1 & x <= n && y >=1 && y <= m;
}
int minStep[MAXN][MAXM];
int bfs() {
    queue<State> q;
    q.push(State(startX, startY));
    State now;
    while(!q.empty()) {
        now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            now.posX += dirX[i];
            now.posY += dirY[i];
            if(legalPos(now.posX, now.posY) && !now.visited[now.posX][now.posY] && grids[now.posX][now.posY] != '#' && minStep[now.posX][now.posY] > now.step+1) {
                if(now.posX == endX && now.posY == endY) {
                    return now.step + 1;
                }
                now.visited[now.posX][now.posY] = true;
                now.step++;
                minStep[now.posX][now.posY] = now.step;
                q.push(now);
                now.step--;
                now.visited[now.posX][now.posY] = false;
            }
            now.posX -= dirX[i];
            now.posY -= dirY[i];
        }
    }
    return -1;
}
int main() {
    while(cin >> n >> m) {
        if(!n && !m) {
            break;
        }
        for(int i = 0; i <= n+1; i++) {
            grids[i][0] = '#';
            grids[m+1][0] = '#';
        }
        for(int i = 0; i <= m+1; i++) {
            grids[0][i] = '#';
            grids[n+1][i] = '#';
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                minStep[i][j] = INF;
                cin >> grids[i][j];
                if(grids[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
                if(grids[i][j] == '*'){
                    endX = i;
                    endY = j;
                }
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}
