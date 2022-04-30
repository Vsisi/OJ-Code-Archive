#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = 2e3 + 10;
const int INF = 0x3fffffff;
int dp[MAXLEN][MAXLEN] = {0};
int main() {
    string a, b;
    cin >> a >> b;
    for(int i = 0; i <= a.length(); i++) {
        for(int j = 0; j <= b.length(); j++) {
            dp[i][j] = INF;
        }
    }
    a = "#" + a;
    b = "#" + b;
    dp[0][0] = 0;
    for(int i = 1; i <= a.length(); i++) {
        dp[i][0] = i;
    }
    for(int i = 1; i <= b.length(); i++) {
        dp[0][i] = i;
    }
    for(int i = 1; i <= a.length(); i++) {
        for(int j = 1; j <= b.length(); j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1];
            }else {
                dp[i][j] = min(dp[i-1][j-1] + 1, 
                    min(dp[i][j-1] + 1, dp[i-1][j] + 1)
                );
            }
        }
    }
    cout << dp[a.length()][b.length()];
    return 0;
}
