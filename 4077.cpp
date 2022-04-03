#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll combination(ll n, ll c) {
    if(c == 1) {
        return n;
    }
    if(n == c) {
        return 1;
    }
    return combination(n-1, c-1) + combination(n-1, c);
}
ll catalan(ll n) {
    return combination(2*n, n) / (n+1);
}
int main() {
    int n;
    cin >> n;
    cout << catalan(n);
    return 0;
}
