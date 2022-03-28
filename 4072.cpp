#include<bits/stdc++.h>
using namespace std;
const string TRUE = "True";
const string FALSE = "False";
const double eps = 1e-7;
double x00, y00;
double calcK(double x, double y) {
    return (y-y00) / (x-x00);
}
int main() {
    int t;
    int n;
    cin >> t;
    double x, y;
    double k;
    while(t--) {
        cin >> n;
        cin >> x00 >> y00;
        if(n == 1) {
            cout << TRUE << endl;
            continue;
        }else if(n == 2) {
            cin >> x >> y;
            cout << TRUE << endl;
            continue;
        }
        cin >> x >> y;
        k = calcK(x, y);
        bool flag = true;
        for(int i = 2; i < n; i++) {
            cin >> x >> y;
            if(flag && fabs(calcK(x, y) - k) > eps) {
                flag = false;
            }
        }
        if(flag) {
            cout << TRUE << endl;
        }else {
            cout << FALSE << endl;
        }
    }
    return 0;
}
