#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 100;
struct Bead{
    int head;
    int tail;
};
Bead beads[MAXN];
typedef long long ll;
ll dp[MAXN][MAXN] = {0};
int main() {
    int n;
    cin >> n;
    for(int i = 0; i <  n; i++) {
        cin >> beads[i].head;
    }
    for(int i = 0; i < n; i++) {
        beads[i].tail = beads[i+1].head;
    }
    beads[n-1].tail = beads[0].head;
    for(int i = 0; i < n; i++) {
        beads[i+n] = beads[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = j+1; k <= j+i-1; k++) {
                dp[i][j] = max(dp[i][j], dp[k-j][j] + dp[j+i-k][k < n ? k : k-n] + beads[j].head * beads[k].head * beads[j+i-1].tail);
            }
        }
    }
    ll res = -1;
    for(int i = 0; i < n; i++) {
        res = max(dp[n][i], res);
    }
    cout << res;
    return 0;
}
