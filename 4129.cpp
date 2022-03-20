#include<bits/stdc++.h>
using namespace std;
const string NO_SOLUTION = "Oop!";
const int SIZE = 110;
const int K = 11;
struct State{
    State() {}
    State(int x, int y, int step):x(x), y(y), step(step) {}
    bool operator<(const State& other) const {
        return step < other.step;
    }
    bool operator>(const State& other) const {
        return step > other.step;
    }
    int x, y;
    int step;
};

vector<string> maze;
priority_queue<State, vector<State>, greater<State>> pq;
bool visited[SIZE][SIZE][K];
int r, c, k;
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
bool legalPos(int x, int y, int step) {
    return x >= 0 && y >= 0 && x < r && y < c && (step % k == 0 || maze[x][y] != '#');
}
int main() {
    // freopen("data.in", "r", stdin);
    int t;
    cin >> t;
    string str;
    int sx, sy;
    int ex, ey;
    while(t--) {
        maze.clear();
        memset(visited, false, sizeof(visited));
        cin >> r >> c >> k;
        for(int i = 0; i < r; i++) {
            cin >> str;
            maze.push_back(str);
            for(int j = 0; j < c; j++) {
                if(str[j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if(str[j] == 'E') {
                    ex = i;
                    ey = j;
                }
            }
        }
        pq.push(State(sx, sy, 0));
        State now;
        bool noSolution = true;
        while(!pq.empty()) {
            now = pq.top();
            pq.pop();
            now.step++;
            for(int i = 0; i < 4; i++) {
                now.x += dirX[i];
                now.y += dirY[i];
                if(legalPos(now.x, now.y, now.step) && !visited[now.x][now.y][now.step%k]) {
                    if(now.x == ex && now.y == ey) {
                        noSolution = false;
                        cout << now.step << endl;
                        break;
                    }
                    pq.push(now);
                    visited[now.x][now.y][now.step % k] = true;
                }
                now.x -= dirX[i];
                now.y -= dirY[i];
            }
            if(!noSolution) {
                break;
            }
        }
        while(!pq.empty()) {
            pq.pop();
        }
        if(noSolution) {
            cout << NO_SOLUTION << endl;
        }
    }
    return 0;
}
