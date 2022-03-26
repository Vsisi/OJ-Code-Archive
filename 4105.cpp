#include<bits/stdc++.h>
using namespace std;
const int MAXR = 220;
const int MAXK = 35;
const string NO_SOLUTION = "oop!";
vector<string> maze;
struct State{
    State(int x, int y, int step=0, int gem=0):x(x), y(y), step(step), gem(gem) {}
    bool operator<(const State& other) const {
        return this->step < other.step;
    }
    bool operator>(const State& other) const {
        return this->step > other.step;
    }
    int x, y, step;
    int gem;
};
int sx, sy;
bool visited[MAXR][MAXR][MAXK];
int r, c, k;
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
vector<pair<int, int>> gate;
void solve() {
    queue<State> pq; 
    pq.push(State(sx, sy));
    visited[sx][sy][0] = true;
    while(!pq.empty()) {
        State now = pq.front(); pq.pop();
        // cout << visited[1][6][31] << endl;
        // cout << now.x << " " << now.y << " " << now.gem << endl;
        // system("pause");
        for(int i = 0; i < 4; i++) {
            now.x += dirX[i];
            now.y += dirY[i];
            if(!visited[now.x][now.y][now.gem]) {
                switch (maze[now.x][now.y]) {
                    case '#': //unsafe
                        break;
                    case '$': //gate
                        for(auto g:gate) {
                            if(!visited[g.first][g.second][now.gem]) {
                                visited[g.first][g.second][now.gem] = true;
                                pq.push(State(g.first, g.second, now.step + 1, now.gem));
                            }
                        }
                        break;
                    case 'E': //end
                        if(now.gem == (1<<k)-1) {
                            cout << now.step + 1 << endl;
                            return;
                        }else {
                            visited[now.x][now.y][now.gem] = true;
                            pq.push(State(now.x, now.y, now.step + 1, now.gem));
                        }
                        break;
                    case '.': //safe
                        pq.push(State(now.x, now.y, now.step + 1, now.gem));
                        visited[now.x][now.y][now.gem] = true;
                        break;
                    case 'S':
                        pq.push(State(now.x, now.y, now.step + 1, now.gem));
                        visited[now.x][now.y][now.gem] = true;
                        break;
                    default: //gem
                        if((now.gem & (1<<(maze[now.x][now.y] - '0'))) == 0) {
                            visited[now.x][now.y][now.gem] = true;
                            int temp = now.gem;
                            now.gem |= (1<<(maze[now.x][now.y] - '0'));
                            // cout << maze[now.x][now.y] << " " << now.x << " " << now.y << " " << temp << " " << now.gem << endl;
                            visited[now.x][now.y][now.gem] = true;
                            pq.push(State(now.x, now.y, now.step + 1, now.gem));
                            now.gem = temp;
                        }else {
                            pq.push(State(now.x, now.y, now.step + 1, now.gem));
                            visited[now.x][now.y][now.gem] = true;
                        }
                        break;
                }
            }
            now.x -= dirX[i];
            now.y -= dirY[i];
        }
    }
    cout << NO_SOLUTION << endl;
}
int main() {
    int t;
    cin >> t;
    string row;
    while(t--) {
        memset(visited, false, sizeof(visited));
        maze.clear();gate.clear();
        
        cin >> r >> c >> k;
        row = ""; for(int i = 0; i < c+2; i++) {row += "#";} maze.push_back(row);
        for(int i = 1; i <= r; i++) {
            cin >> row;
            row = "#" + row + "#";
            for(int j = 1; j <= c; j++) {
                if(row[j] == 'S') {
                    sx = i; sy = j;
                }
                if(row[j] == '$') {
                    gate.push_back(make_pair(i, j));
                }
            }
            maze.push_back(row);
        }
        row = ""; for(int i = 0; i < c+2; i++) {row += "#";} maze.push_back(row);
        solve();
    }
    return 0;
}
