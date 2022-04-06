#include<bits/stdc++.h>
using namespace std;

int main() {
    double n, k;
    cin >> n >> k;
    k /= 100;
    double deposit = 0;
    double nowPrice = 200;
    int m = 1;
    do{
        deposit += n;
        if(deposit >= nowPrice) {
            cout << m;
            return 0;
        }
        m++;
        nowPrice *=  1 + k;
    }while(m <= 20);
    cout << "Impossible";
    return 0;
}
