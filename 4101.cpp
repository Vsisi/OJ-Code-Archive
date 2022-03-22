#include<bits/stdc++.h>
using namespace std;
const int N = 50;
bool visited[N][N];
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};
int n;
vector<string> oreMap;
bool legalPos(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}
void flood(int x, int y, char kind) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            now.first += dirX[i];
            now.second += dirY[i];
            if(legalPos(now.first, now.second) && !visited[now.first][now.second] && oreMap[now.first][now.second] == kind) {
                q.push(make_pair(now.first, now.second));
                visited[now.first][now.second] = true;
            }
            now.first -= dirX[i];
            now.second -= dirY[i];
        }
    }
}
int main() {
    int k;
    cin >> k;
    string str;
    int r, b;
    while(k--) {
        oreMap.clear();
        memset(visited, false, sizeof(visited));
        r = b = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> str;
            oreMap.push_back(str);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && oreMap[i][j] != '#') {
                    visited[i][j] = true;
                    flood(i, j, oreMap[i][j]);
                    if(oreMap[i][j] == 'r') {
                        r++;
                    }else if(oreMap[i][j] == 'b') {
                        b++;
                    }
                }
            }
        }
        cout << r << " " << b << endl;
    }
    return 0;
}
