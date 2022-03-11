#include<bits/stdc++.h>
using namespace std;
int dp[12880][2] = {0};
int main() {
    int n, m;
    cin >> n >> m;
    int w, v;
    int oldi, newi;
    for(int i = 1; i <= n; i++) {
        cin >> w >> v;
        newi = i % 2;
        oldi = (i-1) % 2;
        for(int j = 0; j <= 12880; j++) {
            if(j-w >= 0) {
                dp[j][newi] = max(dp[j-w][oldi] + v, dp[j][oldi]);
            }else {
                dp[j][newi] = dp[j][oldi];
            }
        }
    }
    cout << dp[m][newi];
    return 0;
}
