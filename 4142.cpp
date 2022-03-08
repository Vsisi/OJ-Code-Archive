#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
double getVal(double x) {
    return pow(x, 5) - 15 * pow(x, 4) + 85 * pow(x, 3) - 225 * pow(x, 2) + 274 * x - 121;
}
void solve(double l, double r) {
    // cout << l << " " << r << endl;
    // cout << getVal(l) << " " << getVal(r) << endl;
    // system("pause");
    if(fabs(r-l) < 1e-8) {
        double res = (l+r) / 2;
        printf("%.6lf", res + 5e-7);
        return;
    }
    double mid = (l + r) / 2;
    double valL = getVal(l), valR = getVal(r), valMid = getVal(mid);
    if(valL > eps && valMid < eps) {
        solve(l, mid);
    }else {
        solve(mid, r);
    }
}
int main() {
    solve(1.5, 2.4);
    return 0;
}
