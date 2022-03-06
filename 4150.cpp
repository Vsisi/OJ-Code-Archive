#include<bits/stdc++.h>
using namespace std;
const int MAXN = 11000;
const int INF = 0x3fffffff;
void input(vector<int>&, int n);
int dp[MAXN][4];
int main() {
    int n;
    vector<int> val[3];
    cin >> n;
    input(val[0], n); input(val[1], n); input(val[2], n);
    dp[0][0] = val[0][0];
    dp[0][1] = -INF; //has person on left
    dp[0][2] = val[1][0]; // on right
    dp[0][3] = -INF;
    for(int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][2], dp[i-1][3]) + val[0][i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + val[1][i];
        dp[i][2] = max(dp[i-1][2], dp[i-1][3]) + val[1][i];
        dp[i][3] = max(dp[i-1][0], dp[i-1][1]) + val[2][i];
    }
    cout << max(dp[n-1][0], dp[n-1][1]);
    return 0;
}
void input(vector<int> & dst, int n) {
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        dst.push_back(temp);
    }
}
