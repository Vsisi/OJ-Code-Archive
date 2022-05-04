#include<bits/stdc++.h>
using namespace std;
const int MOD = 19650827;
const int N = 1e3 + 100;
int height[N];
int dp[N][N][2];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> height[i];
        dp[1][i][0] = 1;
        dp[1][i][1] = 0;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < n+1-i; j++) {
            if(height[j] < height[j+i-1]) {
                dp[i][j][0] += dp[i-1][j+1][1];
                dp[i][j][0] %= MOD;
            }
            if(height[j] < height[j+1]) {
                dp[i][j][0] += dp[i-1][j+1][0];
                dp[i][j][0] %= MOD;
            }
            if(height[j+i-1] > height[j]) {
                dp[i][j][1] += dp[i-1][j][0];
                dp[i][j][1] %= MOD;
            }
            if(height[j+i-1] > height[j+i-2]) {
                dp[i][j][1] += dp[i-1][j][1];
                dp[i][j][1] %= MOD;
            }
        }
    }
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 0; j < n+1-i; j++) {
    //         cout << j << " " << i+j-1 << endl;
    //         cout << dp[i][j][0] << " " << dp[i][j][1] << endl << endl;
    //     }
    // }
    cout << (dp[n][0][0] + dp[n][0][1]) % MOD << endl;
    return 0;

}
