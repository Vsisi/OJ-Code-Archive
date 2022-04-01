#include<bits/stdc++.h>
using namespace std;
const int SIZE = 210;
const int MAXT = 12;
const int INF = 0x3fffffff;
int m, n, t;
int sx, sy, ex, ey;
vector<string> mp;
struct State{
    State(int x, int y, int tRemain, int step = 0):x(x), y(y), step(step), tRemain(tRemain) {
    }
    int x, y;
    int step;
    int tRemain;
};
int visited[SIZE][SIZE][MAXT];
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
void solve() {
    queue<State> q;
    q.push(State(sx, sy, t));
    while(!q.empty()) {
        State now = q.front(); q.pop();
        // std::cout << now.x << " " << now.y << " " << now.tRemain << " " << now.step << endl;
        // for(int i = 1; i <= m; i++) {
        //     for(int j = 1; j <= n; j++) {
        //         cout <<setw(15) << visited[i][j][0];
        //     }
        //     cout << endl;
        // }
        // system("pause");
        for(int i = 0; i < 4; i++) {
            now.x += dirX[i];
            now.y += dirY[i];
            if(visited[now.x][now.y][now.tRemain] > now.step) {
                switch (mp[now.x][now.y]) {
                    case '*':
                        now.step++;
                        if(visited[now.x][now.y][now.tRemain] > now.step) {
                            visited[now.x][now.y][now.tRemain] = now.step;
                            q.push(now);
                        }
                        now.step--;
                        break;
                    case '+':
                        std::cout << now.step + 1;
                        return;
                        break;
                    case '#':
                        if(now.tRemain > 0) {
                            now.step++;
                            now.tRemain--;
                            if(visited[now.x][now.y][now.tRemain] > now.step) {
                                visited[now.x][now.y][now.tRemain] = now.step;
                                q.push(now);
                            }
                            now.tRemain++;
                            now.step--;
                        }
                    default: //'X', illegal position
                        break;
                }
            }
            now.x -= dirX[i];
            now.y -= dirY[i];
        }
    }
    std::cout << -1;
    return;
}
int main() {
    cin >> m >> n >> t;
    string line;
    string boundary = "";
    for(int i = 0; i <= m+2; i++) {
        for(int j = 0; j <= n+2; j++) {
            for(int k = 0; k <= t+1; k++) {
                visited[i][j][k] = INF;
            }
        }
    }
    for(int j = 1; j <= n; j++) {
        boundary += "X";
    }
    mp.push_back(boundary);
    for(int i = 1; i <= m; i++) {
        cin >> line;
        line = "X" + line + "X";
        for(int j = 1; j <= n; j++) {
            if(line[j] == '@') {
                sx = i;
                sy = j;
            }else if(line[j] == '+') {
                ex = i;
                ey = j;
            }
        }
        mp.push_back(line);
    }
    visited[sx][sy][t] = 0;
    mp.push_back(boundary);
    solve();
    return 0;
}
