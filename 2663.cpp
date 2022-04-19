#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 30+2;
ll dp[N][10];
void init() {
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    for(int i = 2; i <= 31; i++) {
        dp[i][0] = dp[i-1][1] + dp[i-1][4] + dp[i-1][7];
        dp[i][1] = dp[i-1][6] + dp[i-1][0];
        dp[i][2] = dp[i-1][5];
        dp[i][3] = dp[i-1][4];
        dp[i][4] = dp[i-1][3] + dp[i-1][0];
        dp[i][5] = dp[i-1][2];
        dp[i][6] = dp[i-1][1];
        dp[i][7] = dp[i-1][0];
    }
}
int main() {
    init();
    int n;
    while(cin >> n) {
        if(n == -1) {
            break;
        }
        cout << dp[n+1][0] << endl;
    }
    return 0;
}
