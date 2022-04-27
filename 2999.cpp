#include<bits/stdc++.h>
using namespace std;
const int MAXM = 2200;
int dp[MAXM][MAXM] = {0};
int chain[MAXM][MAXM] = {0};
int a[MAXM] = {0}, b[MAXM] = {0};
int main() {
    int n,  m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxn;
    int tmpChain = 0;
    for(int i = 1; i <= n; i++) {
        maxn = 0;
        tmpChain = 0;
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            chain[i][j] = chain[i-1][j];
            if(a[i] == b[j]) { //a[i] == b[j]
                dp[i][j] = maxn + 1;
                chain[i][j] = tmpChain;
            }
            if(a[i] > b[j] && maxn < dp[i-1][j]) {
                maxn = dp[i-1][j];
                tmpChain = j;
            }
        }
    }
    maxn = 0;
    int bIdx;
    for(int i = 1; i <= m; i++) {
        if(dp[n][i] > maxn) {
            maxn = dp[n][i];
            bIdx = i;
        }
    }
    vector<int> res;
    int i = n;
    while(bIdx) {
        while(a[i] != b[bIdx] && i) {
            i--;
        }
        res.push_back(b[bIdx]);
        bIdx = chain[i][bIdx];
    }
    reverse(res.begin(), res.end());
    cout << maxn << endl;
    for(auto entry:res) {
        cout << entry << " ";
    }
    return 0;
}
