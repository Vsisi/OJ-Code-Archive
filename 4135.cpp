#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool avail(ll x, const ll& m, const vector<ll>& costs) {
    ll cnt = 1;
    ll sum = 0;
    for(auto cost:costs) {
        if(sum + cost <= x) {
            sum += cost;
        }else {
            sum = cost;
            cnt++;
        }
    }
    return cnt <= m;
}
int main() {
    ll n, m;
    cin >> n >> m;
    ll temp;
    vector<ll> costs;
    ll l = 0, r = 0;
    for(ll i = 0; i < n; i++) {
        cin >> temp;
        r += temp;
        l = max(l, temp);
        costs.push_back(temp);
    }
    while((r-l) > 1) {
        ll mid = (l + r) >> 1;
        if(avail(mid, m, costs)) {
            r = mid;
        }else {
            l = mid;
        }
    }
    if(avail(l, m, costs)) {
        cout << l;
    }else {
        cout << r;
    }
    return 0;
}
