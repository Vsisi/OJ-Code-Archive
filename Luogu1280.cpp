#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 100;
const int INF = 0x3fffffff;
int dp[MAXN] = {0};
map<int, vector<int>> mem;
int main() {
    int n, k;
    cin >> n >> k;
    int p, t;
    for(int i = 0; i < k; i++) {
        cin >> p >> t;
        mem[p].push_back(t);
    }
    for(int i = n; i >= 1; i--) {
        if(mem[i].empty()) {
            dp[i] = dp[i+1] + 1;
        }else{
            for(auto d:mem[i]) {
                dp[i] = max(dp[i], dp[i+d]);
            }
        }
    }
    cout << dp[1] << endl;
    return 0;
}
