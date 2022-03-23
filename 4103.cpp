#include<bits/stdc++.h>
using namespace std;
const int SIZE = 55;
int ans = 0;
int baseX = SIZE-1, baseY = (SIZE-1) / 2;
bool visited[SIZE][SIZE];
int n;
int dirX[] = {0, -1, 0}; //right, up, left
int dirY[] = {1, 0, -1};
void search(int x, int y, int stepRemain) {
    if(stepRemain == 0) {
        ans++;
        return;
    }
    for(int i = 0; i < 3; i++) {
        if(!visited[x+dirX[i]][y+dirY[i]]) {
            visited[x+dirX[i]][y+dirY[i]] = true;
            search(x+dirX[i], y+dirY[i], stepRemain-1);
            visited[x+dirX[i]][y+dirY[i]] = false;
        }
    }
}
int main() {
    cin >> n;
    visited[baseX][baseY] = true;
    search(baseX, baseY, n);
    cout << ans;
    return 0;
}
