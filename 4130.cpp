#include <bits/stdc++.h>
using namespace std;
struct State {
    int x, y;
    int step;
    int key;
    bool snack[6];
    bool operator<(const State& newPos) const {
        if(this->step!=newPos.step)
            return this->step>newPos.step;
        return this->key<newPos.key;
    }
}start, over;
int n, m;
char maze[105][105];
bool used[105][105][10];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};
bool legal(State nowPos) {
    return nowPos.x >= 0 && nowPos.x < n && nowPos.y >= 0 && nowPos.y < n;
}
void bfs() {
    priority_queue <State> q;
    while(!q.empty()) q.pop();
    start.step=start.key=0;
    memset(start.snack, 0, sizeof(start.snack));
    q.push(start);
    State nowPos, newPos;
    while(!q.empty()) {
        nowPos=q.top();
        q.pop();
        if(nowPos.x==over.x && nowPos.y==over.y && nowPos.key==n) {
            cout << nowPos.step << endl;
            return;
        }
        for(int i=0; i<4; i++) {
            newPos.x = nowPos.x + dx[i];
            newPos.y = nowPos.y + dy[i];
            newPos.key=nowPos.key;
            if(legal(newPos) && maze[newPos.x][newPos.y]!='#' && !used[newPos.x][newPos.y][newPos.key]) {
                for(int j = 0; j< 6; j++) {
                    newPos.snack[j] = nowPos.snack[j];
                }
                newPos.step = nowPos.step + 1;
                used[newPos.x][newPos.y][newPos.key] = true;
                if(newPos.x == over.x && newPos.y == over.y && newPos.key == m) {
                    cout << newPos.step << endl;
                    return;
                }
                else {
                    if(maze[newPos.x][newPos.y] > 0 && maze[newPos.x][newPos.y] < 6 && !newPos.snack[maze[newPos.x][newPos.y]]) { //snake
                        newPos.snack[maze[newPos.x][newPos.y]] = 1;
                        newPos.step++;
                    }else if(maze[newPos.x][newPos.y]-'0' == nowPos.key+1) {
                        newPos.key++;
                    }
                    q.push(newPos);
                }
            }
        }
    }
    cout << "impossible" << endl;
}

int main()
{
    while(cin >> n >> m && n+m) {
        int seq=1;
        memset(used, 0, sizeof(used));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin>>maze[i][j];
                if(maze[i][j]=='K') {
                    start.x=i, start.y=j;
                    used[i][j][0]=1;
                } else if(maze[i][j]=='T') {
                    over.x=i, over.y=j;
                } else if(maze[i][j]=='S') {
                    maze[i][j]=seq;
                    seq++;
                }
            }
        }
        bfs();
    }
    return 0;
}
