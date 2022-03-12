#include<bits/stdc++.h>
using namespace std;
const int N = 5;
typedef pair<int, int> pii;
const pii src = pii(0, 0), dst = pii(4, 4);
struct Point{
    Point() {
        past.clear();
        memset(went, false, sizeof(went));
    }
    Point(int x, int y):x(x), y(y) {
        memset(went, false, sizeof(went));
        past.push_back(pii(x, y));
    }
    Point(const pii& p):x(p.first), y(p.second) {
        past.push_back(pii(p));
        memset(went, false, sizeof(went));
    }
    int x, y;
    bool went[5][5];
    vector<pii> past;
};
void printPnt(const pii& p) {
    printf("(%d, %d)\n", p.first, p.second);
}
int maze[5][5];
int dirX[4] = {-1, 1, 0, 0}, dirY[4] = {0, 0, -1, 1};
bool legalPos(const Point& p) {
    return p.x >= 0 && p.x < 5 && p.y >= 0 && p.y < 5 && maze[p.x][p.y] == 0 && !p.went[p.x][p.y];
}
void solve() {
    queue<Point> q;
    q.push(Point(src));
    Point now, temp;
    while(!q.empty()) {
        now = q.front(); q.pop();
        if(now.x == dst.first && now.y == dst.second) {
            break;
        }
        for(int i = 0; i < 4; i++) {
            temp = now;
            temp.x += dirX[i];
            temp.y += dirY[i];
            if(legalPos(temp)) {
                temp.past.push_back(pii(temp.x, temp.y));
                temp.went[temp.x][temp.y] = true;
                q.push(temp);
            }
        }
    }
    for(auto point:now.past) {
        printPnt(point);
    }
    return;
}
int main() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }
    solve();
    return 0;
}
