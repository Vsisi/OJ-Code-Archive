#include<bits/stdc++.h>
using namespace std;
bool legal(int a1, int a2, int a3) {
    return (a1+a2) % 2 == 0 && (a2 + a3) % 3 == 0 && (a1+a2+a3) % 5 == 0;
}
int main() {
    int n;
    cin >> n;
    int res = 0;
    for(int a1 = 0; a1 <= n; a1++) {
        for(int a2 = 0; a2 <= n; a2++) {
            for(int a3 = 0; a3 <= n; a3++) {
                if(legal(a1, a2, a3)) {
                    res = max(res, a1 + a2 + a3);
                }
            }
        }
    }
    cout << res;
    return 0;
}
