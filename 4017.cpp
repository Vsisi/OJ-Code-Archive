#include<bits/stdc++.h>
using namespace std;
long long dp[100];
void init() {
    dp[1] = 1;
    dp[2] = 2;
    for(long long i = 3; i <= 34; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
}
int main() {
    long long n;
    init();
    while(cin >> n) {
        cout << dp[n] << endl;
    }
}
