#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 23;
ll w[MAX][MAX][MAX];
const int INF = INT32_MAX;
ll getW(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if(w[a][b][c] != INF) {
        return w[a][b][c];
    }
    if(a < b && b < c) {
        w[a][b][c] = getW(a, b, c-1) + getW(a, b-1, c-1) - getW(a, b-1, c);
        return w[a][b][c];
    }
    w[a][b][c] = getW(a-1, b, c) + getW(a-1, b-1, c) + getW(a-1, b, c-1) - getW(a-1, b-1, c-1);
    return w[a][b][c];

}
void init() {
    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= 20; j++) {
            for(int k = 0; k <= 20; k++) {
                w[i][j][k] = INF;
            }
        }
    }
    w[0][0][0] = 1;
    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= 20; j++) {
            for(int k = 0; k <= 20; k++) {
                w[i][j][k] = getW(i, j, k);
            }
        }
    }
}
inline void formatOut(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        printf("w(%d, %d, %d) = %d\n", a, b, c, w[0][0][0]);
    }else if(a > 20 || b > 20 || c > 20) {
        printf("w(%d, %d, %d) = %d\n", a, b, c, w[20][20][20]);
    }else {
        printf("w(%d, %d, %d) = %d\n", a, b, c, w[a][b][c]);
    }
}
int getWW(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        return w[0][0][0];
    }else if(a > 20 || b > 20 || c > 20) {
        return w[20][20][20];
    }else{
        return w[a][b][c];
    }
}
int main() {
    int a, b, c;
    init();
    while(cin >> a >> b >> c) {
        if(a == -1 && b == -1 && c == -1) {
            break;
        }
        formatOut(a, b, c);
    }
    return 0;
}
