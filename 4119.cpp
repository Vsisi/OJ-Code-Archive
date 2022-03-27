#include<bits/stdc++.h>
using namespace std;
const int N = 55;
typedef long long ll;
ll b[N][N];
void init();
ll kPartition(int n, int k) {
    if(k > n) {
        return 0;
    }
    if(b[n][k]) {
        return b[n][k]    ;
    }
    ll res = 0;
    for(int i = 1; i <= k; i++) {
        res += kPartition(n-k, i);
    }
    b[n][k] = res;
    return res;
}
ll ans[N] = {0, 1, 1, 2, 2, 3, 4, 5, 6, 8, 10, 12, 15, 18, 22, 27, 32, 38, 46, 54, 64, 76, 89, 104, 122, 142, 165, 192, 222, 256, 296, 340, 390, 448, 512, 585, 668, 760, 864, 982, 1113, 1260, 1426, 1610, 1816, 2048, 2304, 2590, 2910, 3264, 3658};
map<string, bool> appeared;
void makeSheet();
void searchPartition(int n, bitset<N> curBan, ll& tempAns) {
    if(n == 0) {
        if(!appeared[curBan.to_string()]) {
            appeared[curBan.to_string()] = true;
            tempAns++;
        }
        return; 
    }
    for(int i = 1; i <= n; i++) {
        if(!curBan.test(i)) { //have not used
            curBan.set(i);
            searchPartition(n-i, curBan, tempAns);
            curBan.reset(i);
        }
    }
}
int main() {
    init();
    // makeSheet();
    int n, k;
    while(cin >> n >> k) {
        ll res = 0;
        cout << kPartition(n, k) << endl;
        cout << ans[n] << endl << ans[n] << endl;
    }
    return 0;
}
void init() {
    memset(b, 0, sizeof(b));
    for(int i = 0; i < N; i++) {
        b[i][1] = 1;
        b[i][i] = 1;
    }
}
void makeSheet() {
    for(int i = 1; i <= 50; i++) {
        ll tempAns = 0;
        appeared.clear();
        searchPartition(i, 0, tempAns);
        cout << tempAns << ", ";
    }
    return;
}
