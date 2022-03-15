#include<bits/stdc++.h>
using namespace std;
const int N = 12;
int n, m;
bool legal(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
struct State{
    State() {
        memset(visited, false, sizeof(visited));
    }
    State(int x, int y):x(x), y(y) {
        memset(visited, false, sizeof(visited));
        visited[x][y] =  true;
        step = 1;
    }
    int x, y;
    int step;
    bool visited[N][N];
};
int dirX[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dirY[] = {1, -1, 2, -2, 2, -2, 1, -1};
int main() {
    int t;
    cin >> t;
    int x, y;
    int res = 0;
    queue<State> q;
    while(t--) {
        cin >> n >> m >> x >> y;
        q.push(State(x, y));
        long long cnt = 0;
        while(!q.empty()) {
            State now = q.front();
            q.pop();
            for(int i = 0; i < 8; i++) {
                now.x += dirX[i];
                now.y += dirY[i];
                if(legal(now.x, now.y) && !now.visited[now.x][now.y]) {
                    now.visited[now.x][now.y] = true;
                    now.step++;
                    if(now.step < m*n) {
                        q.push(now);
                    }else {
                        cnt++;
                    }
                    now.step--;
                    now.visited[now.x][now.y] = false;
                }
                now.x -= dirX[i];
                now.y -= dirY[i];
            }
        }
        cout << cnt << endl;
    }
}
