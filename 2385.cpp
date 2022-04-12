#include<bits/stdc++.h>
using namespace std;
const int MAXT = 1010;
const int MAXW = 35;
int dp[MAXT][2][MAXW];
int main() {
    int t, w;
    cin >> t >> w;
    int treeId;
    bool tree[2][MAXT];
    memset(tree, false, sizeof(tree));
    for(int i = 1; i <= t; i++) {
        cin >> treeId;
        tree[treeId - 1][i] = true;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][w] = 0; //at time t, tree 1, w step remain
    for(int i = 1; i <= t; i++) {
        for(int j = 0; j <= 1; j++) {
            for(int k = 0 ; k <= w; k++) {
                if(tree[j][i]) { //has apple falls at this time
                    dp[i][j][k] = max(
                        dp[i-1][j][k], //not moved
                        dp[i-1][j^1][k+1] //move from other tree
                    ) + 1;
                }else { //no apple falls
                    dp[i][j][k] = max(
                        dp[i-1][j][k],
                        dp[i-1][j^1][k+1]
                    );
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= w; j++) {
            res = max(res, dp[t][i][j]);
        }
    }
    cout << res << endl;
    return 0;
}
