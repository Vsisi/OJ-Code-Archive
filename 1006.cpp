#include<bits/stdc++.h>
using namespace std;

const int pCycle = 23;
const int eCycle = 28;
const int iCycle = 33;

void formatPrint(int res);
int posAdjust(int num, int mod);
int solveOne(int a, int m);
int exgcd(int a, int b, int& x, int& y);

int main() {
    int p, e, i, d;
    int a, b, c;
    int x, y, z;
    while(1) {
        cin >> p >> e >> i >> d ;
        if(p == -1 && e == -1 && i == -1 && d == -1) {
            break;
        }
        a = posAdjust(p-d, pCycle);
        b = posAdjust(e-d, eCycle);
        c = posAdjust(i-d, iCycle);

        formatPrint((
            solveOne(eCycle*iCycle, pCycle) * a + 
            solveOne(pCycle*iCycle, eCycle) * b + 
            solveOne(pCycle*eCycle, iCycle) * c
        ) % (eCycle * pCycle * iCycle));
    }
    return 0;
}

int solveOne(int a, int m) { //ax = 1 (mod m), (a, m) = d = 1
    int res, temp;
    exgcd(a%m, m, res, temp);
    return posAdjust(res, m)  * a;
}
int exgcd(int a, int b, int& x, int& y) {
    if(a < b) { //adjust
        return exgcd(b, a, y, x);
    }
    if(b == 0) {
        x = 1; 
        y = 0;
        return a;
    }else {
        int x1;
        int d = exgcd(b, a % b, x1, x);
        y = x1 - a / b * x;
        return d;
    }
}
int posAdjust(int num, int mod) {
    while(num < 0) {
        num += mod;
    }
    return num;
}
void formatPrint(int res) {
    static int cases = 1;
    printf("Case %d: the next triple peak occurs in %d days.\n", cases++, res == 0 ? 21252 : res);
}
