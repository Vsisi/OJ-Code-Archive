#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
double getVal(double x) {
    return pow(x, 3) - 5 * pow(x, 2) + 10 * x - 80;
}
void solve(double l, double r) {
    if(fabs(r - l) < eps) {
        printf("%.9lf", (l+r)/2);
        return;
    }
    double mid = (l+r) / 2;
    double valL = getVal(l), valR = getVal(r), valMid = getVal(mid);
    if(valL < eps && valMid > eps) {
        solve(l, mid);
    }else {
        solve(mid, r);
    }
}
int main() {
    solve(5, 6);
    return 0;
}
