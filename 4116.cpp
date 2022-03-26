#include<bits/stdc++.h>
using namespace std;
const int MAXN = 220;
vector<string> maze;
bool visited[MAXN][MAXN];
int knightX, knightY;
struct Position{
    Position(int x, int y, int step=0):x(x), y(y), step(step) {
    }
    bool operator<(const Position& other) const {
        return this->step < other.step;
    }
    bool operator>(const Position& other) const {
        return this->step > other.step;
    }
    int x, y, step;
};
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
void solve() {
    priority_queue<Position, vector<Position>, greater<Position>> pq;
    pq.push(Position(knightX, knightY));
    visited[knightX][knightY] = true;
    while(!pq.empty()) {
        Position now = pq.top();
        // cout << now.x << " " << now.y << " " << now.step << endl;
        // system("pause");
        pq.pop();
        for(int i = 0; i < 4; i++) {
            now.x += dirX[i];
            now.y += dirY[i];
            if(!visited[now.x][now.y]) {
                visited[now.x][now.y] = true;
                switch (maze[now.x][now.y]) {
                    case '@':
                        now.step++;
                        pq.push(now);
                        now.step--;
                        break;
                    case 'x':
                        now.step += 2;
                        pq.push(now);
                        now.step -= 2;
                        break;
                    case 'a':
                        cout << now.step + 1 << endl;
                        return;
                        break;
                    default:
                        break;
                }
            }
            now.x -= dirX[i];
            now.y -= dirY[i];
        }
    }
    cout << "Impossible" << endl;
    return;
}
int main() {
    int s;
    int n, m;
    string row;
    cin >> s;
    while(s--) {
        maze.clear();
        memset(visited, false, sizeof(visited));
        cin >> n >> m;
        row = "";for(int i = 0; i < m+2; i++) {row += "#";}maze.push_back(row);
        for(int i = 1; i <= n; i++) {
            cin >> row;
            row = "#" + row + "#";
            for(int j = 1; j <= m; j++) {
                if(row[j] == 'r') {
                    knightX = i; knightY = j;
                }
            }
            maze.push_back(row);
        }
        row = "";for(int i = 0; i < m; i++) {row += "#";}maze.push_back(row);
        solve();
    }
    return 0;
}
