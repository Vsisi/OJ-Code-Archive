#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 55;
const ll MAXM = 13;
const ll INF = INT64_MAX >> 1;
ll nums[MAXN];
ll n, m;
ll dpMin[MAXN][MAXN][MAXM];
ll dpMax[MAXN][MAXN][MAXM];
ll presum[2 * MAXN];
ll mod(ll x) {
    if(x > 0) {
        while(x >= 10) {
            x -= 10;
        }
    }
    if(x < 0) {
        while(x < 0) {
            x += 10;
        }
    }
    return x;
}
ll solveMin(ll l, ll numRemain, ll k) {
    ll res = 0;
    if(k == 0) {
        return -1;
    }
    if(k == 1) {
        res = mod(presum[l+numRemain] - presum[l]);
        return mod(res);
    }
    ll temp = 0;
    int idx;
    for(ll i = 1; i < numRemain; i++) {
        temp = mod(presum[l+i] - presum[l]);
        idx = (l + i) % n;
        if(dpMin[idx][numRemain-i][k-1] == -1) {
            dpMin[idx][numRemain-i][k-1] = solveMin(idx, numRemain - i, k-1);
        }
        res = min(res, temp * dpMin[idx][numRemain-i][k-1]);
    }
    return res;
}
ll solveMax(ll l, ll numRemain, ll k) {
    ll res = 0;
    if(k == 0) {
        return -1;
    }
    if(k == 1) {
        res = mod(presum[l+numRemain] - presum[l]);
        return mod(res);
    }
    ll temp = 0;
    int idx;
    for(ll i = 1; i < numRemain; i++) {
        temp = mod(presum[l+i] - presum[l]);
        idx = (l + i) % n;

        if(dpMax[idx][numRemain-i][k-1] == -1) {
            dpMax[idx][numRemain-i][k-1] = solveMax(idx, numRemain - i, k-1);
        }
        res = max(res, temp * dpMax[idx][numRemain-i][k-1]);
    }
    return res;
}
void init() {
    for(ll i = 0; i < MAXN; i++) {
        for(ll j = 0; j < MAXN; j++) {
            for(ll k = 0; k < MAXM; k++) {
                dpMin[i][j][k] = -1;
                dpMax[i][j][k] = -1;
            }
        }
    }
}
int main() {
    init();
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        cin >> nums[i];
    }
    presum[0] = 0;
    for(int i = 1; i <= n; i++) {
        presum[i] = mod(presum[i-1] + nums[i-1]);
    }
    for(int i = n+1; i <= 2 * n; i++) {
        presum[i] = mod(presum[i-1] + nums[i-n-1]);
    }
    ll resMin = INF, resMax = 0;
    ll temp = 0;
    if(m > 1) {
        for(ll i = 0; i < n; i++) {
            for(ll j = 1; j < n; j++) { //consider j nums from position i
                temp = mod(presum[i+j] - presum[i]);
                resMin = min(solveMin(i + j, n - j, m-1) * temp, resMin);
                resMax = max(solveMax(i + j, n - j, m-1) * temp, resMax);
            }
        }
    }else {
        resMin = presum[n];
        resMax = presum[n];
    }
    cout << resMin << endl;
    cout << resMax << endl;
    return 0;
}
