#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5050;
int** dp;
int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    string strrev = str;
    reverse(strrev.begin(), strrev.end());
    dp = new int*[n];
    for(int i = 0; i < n; i++) {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
        for(int j = 0; j < n; j++) {
            if(str[i] == strrev[j]) {
                if(i-1 < 0 || j-1 < 0) {
                    dp[i][j] = 1;
                }else {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }else {
                int x = i-1 >= 0 ? dp[i-1][j] : 0;
                int y = j-1 >= 0 ? dp[i][j-1] : 0;
                dp[i][j] = max(x, y);
            }
        }
        if(i-2 >= 0) {
            delete[] dp[i-1];
        }
    }
    cout << n - dp[str.length()-1][str.length()-1];
    return 0;
}
