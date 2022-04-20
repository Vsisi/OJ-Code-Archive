#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int dp[N] = {0};
int main() {
    int n, tmp;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    dp[0] = 1;
    int maxn = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]++;
        maxn = max(dp[i], maxn);
    }
    cout << maxn;
    return 0;
}
