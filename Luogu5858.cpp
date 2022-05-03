#include<bits/stdc++.h>
using namespace std;
const int N = 5050;
typedef long long ll;
const ll INF = INT64_MAX >> 1;
ll dp[N][N] = {0};
ll a[N];
int main() {
    ll n, w, s;
    cin >> n >> w >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= w; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][1] = a[0];
    deque<ll> val, idx;
    for(ll i = 1; i < n; i++) {
        while(!val.empty()) {
            val.pop_back();
            idx.pop_back();
        }
        val.push_back(dp[i-1][w]);
        idx.push_back(w);
        for(ll j = w; j >= 1; j--) {
            while(!idx.empty() && idx.front() > j+s-1) {
                idx.pop_front();
                val.pop_front();
            }
            while(!val.empty() && val.back() < dp[i-1][j-1]) {
                val.pop_back();
                idx.pop_back();
            }
            val.push_back(dp[i-1][j-1]);
            idx.push_back(j-1);
            dp[i][j] = max(dp[i][j], val.front() + j * a[i]);
        }
    }
    ll res = -INF;
    for(int i = 1; i <= w; i++) {
        res = max(res, dp[n-1][i]);
    }
    cout << res;
    return 0;
}
