#include<bits/stdc++.h>
using namespace std;
const int MAX = 55;
int stu[MAX][MAX];
int dp[MAX][MAX][MAX][MAX];
int main() {
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> stu[i][j];
            dp[i][j][i][j] = -0x3f3f3f3f;
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                for(int h = j+1; h <= n; h++) {
                    dp[i][j][k][h] = max(
                        max(dp[i-1][j][k-1][h], dp[i][j-1][k-1][h]),
                        max(dp[i-1][j][k][h-1], dp[i][j-1][k][h-1])
                    ) + stu[i][j] + stu[k][h];
                }
            }
        }
    }
    cout << dp[m][n-1][m-1][n];
    return 0;
}
