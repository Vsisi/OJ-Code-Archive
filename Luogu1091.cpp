#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int height[N];
int inc[N], decr[N];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> height[i];
        inc[i] = decr[i] = 1;
    }
    inc[0] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(height[i] > height[j]) {
                inc[i] = max(inc[j] + 1, inc[i]);
            }
        }
    }
    for(int i = n-2; i >= 0; i--) {
        for(int j = n-1; j > i; j--) {
            if(height[i] > height[j]) {
                decr[i] = max(decr[i], decr[j] + 1);
            }
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout <<height[i] << " " << inc[i] <<  " " << decr[i] << endl;
    // }
    int maxLen = -1;
    for(int i = 0; i < n; i++) {
        maxLen = max(maxLen, inc[i] + decr[i] - 1);
    }
    cout << n - maxLen;
    return 0;
}
