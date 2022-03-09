#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
bool isPrime(long long n) {
    if(n == 1) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    for(long long i = 2; i <= sqrt(n) + 1; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
int decompose(int n) {
    long long res = 0;
    for(long long i = 1; i <= n; i++) {
        if(isPrime(n-i) && isPrime(i)) {
            res = max(res, i * (n-i));
        }
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    cout << decompose(n);
    return 0;
}
