#include<bits/stdc++.h>
using namespace std;
const int MAXN = 12;
int grid[MAXN][MAXN] = {0};
int dp[MAXN][MAXN][MAXN][MAXN] = {0};
int main() {
    int n;
    cin >> n;
    int a, b, c;
    while(cin >> a >> b >> c) {
        if(!a && !b && !c) {
            break;
        }
        grid[a][b] = c;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int h = 1; h <= n; h++) {
                    dp[i][j][k][h] = max(
                        max(dp[i-1][j][k-1][h], dp[i][j-1][k-1][h]),
                        max(dp[i-1][j][k][h-1], dp[i][j-1][k][h-1])
                    ) + grid[i][j] + grid[k][h];
                    if(i == k && j == h) {
                        dp[i][j][k][h] -= grid[i][j];
                    }
                }
            }
        }
    }
    cout << dp[n][n][n][n];
    return 0;
}
