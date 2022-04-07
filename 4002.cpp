#include<bits/stdc++.h>
using namespace std;
const int MAXM = 300;
const string NO_SOLUTION = "BeiJu";
int cnt[MAXM] = {0};
int main() {
    int n, m;
    cin >> n >> m;
    int p;
    vector<int> ps;
    for(int i = 0; i < n; i++) {
        cin >> p;
        cnt[p]++;
        ps.push_back(p);
    }
    for(auto p:ps) {
        if(cnt[p] > 1) {
            cout << cnt[p] - 1 << endl;
        }else {
            cout << NO_SOLUTION << endl;
        }
    }
    return 0;
}
