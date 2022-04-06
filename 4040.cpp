#include<bits/stdc++.h>
using namespace std;
const double INF = DBL_MAX;
int main() {
    int n;
    int m;
    double p;
    while(cin >> n) {
        if(n == -1) {
            break;
        }
        int bookNum = 0;
        double totPrice = 0;
        for(double i = 0; i < n; i++) {
            cin >> m >> p;
            bookNum += m;
            totPrice += p * m;
        }
        double noStrategy = totPrice + 20;
        double strategy1 = INF;
        double strategy2 = INF;
        if(bookNum > 3) {
            strategy2 = 20 + totPrice * 0.95;
        }
        if(totPrice > 100) {
            strategy1 = totPrice;
        }
        cout << min(min(strategy1, strategy2), noStrategy) << endl;
    }
    return 0;
}
