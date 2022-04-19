#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int dp[N][N];
int main() {
    string x, y;
    while(cin >> x >> y) {
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < x.length(); i++) {
            for(int j = 0; j < y.length(); j++) {
                if(x[i] == y[j]) {
                    if(i-1 < 0 || j-1 < 0) {
                        dp[i][j] = 1;
                        continue;
                    }
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else {
                    if(i-1 < 0 || j-1 < 0) {
                        if(i-1 < 0 && j-1 < 0) {
                            dp[i][j] = 0;
                        }else if(i-1 < 0) {
                            dp[i][j] = max(0, dp[i][j-1]); 
                        }else {
                            dp[i][j] = max(dp[i-1][j], 0);
                        }
                    }else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        cout << dp[x.length()-1][y.length()-1] << endl;
    }
    return 0;
}
