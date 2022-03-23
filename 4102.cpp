#include<bits/stdc++.h>
using namespace std;
const int N = 1050, M = 510, K = 110;
int dp[N][M];
bitset<K> sel[N][M];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int ball, dmg;
    vector<int> dmgs;
    for(int i = 0; i < k; i++) {
        cin >> ball >> dmg;
        dmgs.push_back(dmg);
        for(int j = n; j >= ball; j--) {
            for(int k = m; k >= dmg; k--) {
                if(dp[j][k] >= dp[j-ball][k-dmg]+1) { //leave

                }else {
                    dp[j][k] = dp[j-ball][k-dmg] + 1;
                    sel[j][k] = sel[j-ball][k-dmg];
                    sel[j][k].set(i);
                }
            }
        }
    }
    int c = dp[n][m], r = INT32_MAX;
    int tempR;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(dp[i][j] == c) {
                tempR = 0;
                for(int h = 0; h < k; h++) {
                    if(sel[i][j].test(h)) {
                        tempR += dmgs[h];
                        // cout << dmgs[h] << endl;
                    }
                }
                // cout << endl;
                r = min(tempR, r);
            }
        }
    }
    cout << c << " " << m - r << endl;
    return 0;
}
