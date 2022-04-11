#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD = 1e9;
const int MAXN = 5e6;
ll dp[MAXN];
void calc(int n) {
    for(int i = 3; i <= n; i++) {
        if(i % 2 == 0) {
            dp[i] = (dp[i-1] + dp[i/2]) % MOD;
        }else {
            dp[i] = dp[i-1];
        }
    }
}
int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    calc(n);
    cout << dp[n] << endl;
    return 0;
}
