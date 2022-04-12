#include<bits/stdc++.h>
using namespace std;
const int MAXM = 1e5+5;
const int MAXN = 1e2+5;
bool dp[MAXM]; //consider front i-1 kinds of coins
int main() {
    int n, m;
    int aTmp, cTmp;
    vector<int> a, c;
    while(cin >> n >> m) {
        if(!n && !m) {
            break;
        }
        a.clear(); c.clear();
        for(int i = 0; i < n; i++) {
            cin >> aTmp;
            a.push_back(aTmp);
        }
        for(int i = 0; i < n; i++) {
            cin >> cTmp;
            c.push_back(cTmp);
        }
        memset(dp, false, sizeof(dp));
        for(int i = 0; i <= c[0] && i * a[0] <= m; i++) {
            dp[i * a[0]] = true;
        }
        for(int i = 1; i < n; i++) {
            for(int j = m; j >= 1; j--) {
                if(!dp[j]) {
                    for(int k = 1; k <= c[i] && j - k * a[i] >= 0 && !dp[j]; k++) {
                        dp[j] = dp[j - k * a[i]];
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= m; i++) {
            if(dp[i]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
