#include<bits/stdc++.h>
using namespace std;
const int N = 55;
void init();
typedef long long ll;
ll b[N][N];
ll getB(int n, int k) {
    if(n < k) {
        return 0;
    }
    if(b[n][k]) {
        return b[n][k];
    }
    ll res = 0;
    for(int i = 1; i <= k; i++) {
        res = res + getB(n-k, i);
    }
    b[n][k] = res;
    return res;
}
int main() {
    init();
    int n;
    while(cin >> n) {
        ll res = 0;
        for(int i = 1; i <= n; i++) {
            res = res + getB(n, i);
        }
        cout << res << endl;
    }
    return 0;
}
void init() {
    memset(b, 0, sizeof(b));
    for(int i= 0; i < N; i++) {
        b[i][1] = 1;
        b[i][i] = 1;
    }
}
