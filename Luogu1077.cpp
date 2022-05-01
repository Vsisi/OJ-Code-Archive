#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e6+7;
const int MAXN = 110;
const int MAXM = 110;
int a[MAXN];
int dp[MAXN][MAXM];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i <= min(a[0], m); i++) {
        dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= a[i] && j - k >= 0; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
            }
        }
    }
    cout << dp[n-1][m] << endl;
    return 0;
}
