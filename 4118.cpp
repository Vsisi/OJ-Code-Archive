#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int dp[N][2];
int main() {
    int t;
    cin >> t;
    int n, k;
    vector<int> pos, profit;
    int temp;
    while(t--) {
        memset(dp, 0, sizeof(dp));
        pos.clear(); profit.clear();
        cin >> n >> k;
        pos.push_back(-0x3fffffff); profit.push_back(0);
        for(int i = 0; i < n; i++) {
            cin >> temp;
            pos.push_back(temp);
        }
        for(int i = 0; i < n; i++) {
            cin >> temp;
            profit.push_back(temp);
        }
        int j;
        for(int i = 1; i <= n; i++) {
            for(j = 0; pos[i]-pos[j] > k; j++) {
                dp[i][1] = max(dp[i][1], max(dp[j][0] + profit[i], dp[j][1] + profit[i]));
                dp[i][0] = max(dp[i][0], max(dp[j][0], dp[j][1]));
            }
            for(; j < i; j++) {
                dp[i][0] = max(dp[i][0], max(dp[j][0], dp[j][1]));
            }
        }
        // for(int i = 0; i <= n; i++) {
        //     cout << dp[i][0] <<" " << dp[i][1] << endl;
        // }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}
