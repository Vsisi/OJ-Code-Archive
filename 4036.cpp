#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 10007;
const int MAXN = 1010;
ll c[MAXN][MAXN];
ll combination(ll n, ll k) {
    if(n == k || n == 0) {
        return 1;
    }else if(k == 1) {
        return n;
    }else if(c[n][k] != 0){
        return c[n][k];
    }
    c[n][k] = (combination(n-1, k-1) + combination(n-1, k)) % MOD;
    return c[n][k];
}
ll power(ll n, ll power) {
    ll res = 1;
    for(ll i = 0; i < power; i++) {
        res = (res * n) % MOD;
    }
    return res;
}
int main() {
    memset(c, 0, sizeof(c));
    ll a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    a %= MOD; b %= MOD;
    cout << (((power(a, n) * power(b, m)) % MOD) * combination(k, n)) % MOD;
    return 0;
}
