#include<bits/stdc++.h>
using namespace std;
const int N = 16;
const int INF = 0x3fffffff;
int dis[N][N];
int n;
int dp[2][N][1 << N];
set<int> sets[2][N];
void solve() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 1<<N; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    int now = 1;
    for(int i = 0; i < n-1; i++) {
        dp[now][i][0] = dis[i][n-1];
        sets[now][i].insert(0);
    }
    now = 1 - now;
    int res = INF;
    for(int size = 2; size < n; size++) {
        for(int i = 0; i < n-1; i++) {
            for(auto s:sets[1-now][i]) {
                for(int j = 0; j < n-1; j++) {
                    if(i != j && ((s >> j)&1) == 0) {
                        dp[now][j][s | (1<<i)] = min(dp[now][j][s | (1 << i)], dp[1-now][i][s] + dis[j][i]);
                        sets[now][j].insert(s | (1 << i));
                        if(size == n-1 && j == 0) {
                            res = min(res, dp[now][j][s | (1 << i)]);
                        }
                    }
                }
            }
            sets[1-now][i].clear();
        }
        now = 1 - now;
    }
    cout << res << endl;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dis[i][j];
        }
    }
    solve();
    return 0;
}
