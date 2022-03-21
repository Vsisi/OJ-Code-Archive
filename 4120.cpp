//在床上想出来的，令人感叹
#include<bits/stdc++.h>
using namespace std;
const int N = 205;
const int X = 10100;
int dp[X];
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coin;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        coin.push_back(temp);
    }
    sort(coin.begin(), coin.end());
    dp[0] = 1;
    dp[coin[0]] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = x; j >= coin[i]; j--) {
            dp[j] += dp[j - coin[i]];
        }
    }
    int cnt = 0;
    vector<int> res;
    bool sign = true;
    for(int i = 0; i < n; i++) {
        temp = 0;
        sign = true;
        for(int j = x; j >= 0; j -= coin[i]) {
            if(sign) {
                temp += dp[j];
            }else {
                temp -= dp[j];
            }
            sign = !sign;
        }
        if(temp == 0) {
            cnt++;
            res.push_back(coin[i]);
        }
    }
    cout << cnt << endl;
    if(cnt) {
        for(auto r:res) { 
            cout << r << " ";
        }
    }else {
        cout << endl;
    }
    return 0;
}
