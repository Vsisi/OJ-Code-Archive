#include<bits/stdc++.h>
using namespace std;
const double epsilon = 1e-6;
const string info = "card(s)";
int main() {
    double c;
    while(cin >> c) {
        if((c - 0.00) < epsilon) {
            break;
        }
        double n = 2;
        double sum = 0;
        while(sum < c) {
            sum += 1.0/n;
            n = n + 1;
        }
        cout << n-2 << " " << info << endl;
    }
    return 0;
}
