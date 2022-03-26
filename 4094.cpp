#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    double s;
    cin >> n >> s;
    double t, v;
    double res = 0;
    for(int i = 0; i < n; i++) {
        cin >> t >> v;
        res = max(res, t + s / v);
    }
    cout << int(res);
    return 0;
}
