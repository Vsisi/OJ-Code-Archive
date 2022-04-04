#include<bits/stdc++.h>
using namespace std;
bool irrelevant35(int x) {
    if(x % 3 == 0|| x % 5 == 0) {
        return false;
    }
    stringstream ss;
    string xStr;
    ss << x;
    ss >> xStr;
    for(auto c:xStr) {
        if(c == '3' || c == '5') {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    long long res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(irrelevant35(i)) {
            res += i * i;
        }
    }
    cout << res;
    return 0;
}
