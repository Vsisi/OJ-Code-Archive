#include<bits/stdc++.h>
using namespace std;
const int MAXMN = 220;
const int MAXK = 1010;
int m, n;
int k;
int mat[MAXMN][MAXMN];
int series[MAXK];
bool legalPos(int x, int y) {
    return x >= 0 && y >= 0 && x < m && y < n;
}
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
bool visited[MAXMN][MAXMN];
bool match(int x, int y, int idx) {
    if(idx == k) {
        return true;
    }
    for(int i = 0; i < 4; i++) {
        x += dirX[i];
        y += dirY[i];
        if(legalPos(x, y) && !visited[x][y] && series[idx] == mat[x][y]) {
            visited[x][y] = true;
            if(match(x, y, idx+1)) {
                return true;
            }
            visited[x][y] = false;
        }
        x -= dirX[i];
        y -= dirY[i];
    }
    return false;
}
int main() {
    memset(visited, false, sizeof(visited));
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> series[i];
    }
    bool hasSolution = false;
    for(int i = 0 ; i < m && !hasSolution; i++) {
        for(int j = 0; j < n && !hasSolution; j++) {
            if(mat[i][j] == series[0]) {
                visited[i][j] = true;
                hasSolution = match(i, j, 1);
                visited[i][j] = false;
            }
        }
    }
    cout << hasSolution;
    return 0;
}
