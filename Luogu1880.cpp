#include<bits/stdc++.h>
using namespace std;
const int N = 220;
const int INF = 0x3fffffff;
int rock[N];
int dpMin[N][N], dpMax[N][N];
int presum[N] = {0};
int main() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dpMin[i][j] = INF;
            dpMax[i][j] = -1;
        }
    }
    int n;
    int resMin = INF, resMax = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> rock[i];
        rock[i+n] = rock[i];
        dpMax[1][i] = 0;
        dpMax[1][i+n] = 0;
        dpMin[1][i] = 0;
        dpMin[1][i+n] = 0;
    }
    presum[0] = rock[0];
    for(int i = 1; i < n; i++) {
        presum[i] = presum[i-1] + rock[i];
    }
    for(int i = 0; i < n; i++) {
        presum[n+i] = presum[n+i-1] + rock[i];
    }
    int tmp;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            tmp = presum[j+i-1] - presum[j] + rock[j];
            for(int k = j+1; k <= j+i-1; k++) {
                dpMin[i][j] = min(dpMin[i][j], dpMin[k-j][j] + dpMin[j+i-k][k < n ? k : k-n] + tmp);
                dpMax[i][j] = max(dpMax[i][j], dpMax[k-j][j] + dpMax[j+i-k][k < n ? k : k-n] + tmp);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        resMin = min(resMin, dpMin[n][i]);
        resMax = max(resMax, dpMax[n][i]);
    }
    cout << resMin << endl << resMax << endl;
    return 0;
}
