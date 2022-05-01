#include<bits/stdc++.h>
using namespace std;
const int MOD  = 998244353;
const int MAXN = 1e3 + 10;
const int MAXV = 4e4 + 10;
const int offset = 2e4;
int h[MAXN];
int dp[MAXN][MAXV];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        res = (res + 1) % MOD;
        for(int j = i-1; j >=0 ;j--) {
            dp[i][h[i] - h[j] + offset] += dp[j][h[i] - h[j] + offset] + 1;
            dp[i][h[i] - h[j] + offset] %= MOD;
            res += dp[j][h[i] - h[j] + offset] + 1;
            res %= MOD;
        }
    }
    cout << res;
    return 0;
}
