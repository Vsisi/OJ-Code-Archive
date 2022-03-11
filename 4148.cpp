#include<bits/stdc++.h>
using namespace std;
const int phy = 23;
const int emo = 28;
const int itg = 33;
void exgcd(int a, int b, int& x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    exgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
}
void formatOut(int caseCnt, int res) {
    printf("Case %d: the next triple peak occurs in %d days.\n", caseCnt, res);
    return;
}
int solve(int p, int e, int i, int d) {
    int c1, c2, c3;
    int temp;
    exgcd(emo*itg, phy, c1, temp);
    while(c1 < 0) {c1 += phy;}
    exgcd(phy*itg, emo, c2, temp);
    while(c2 < 0) {c2 += emo;}
    exgcd(emo*phy, itg, c3, temp);
    while(c3 < 0) {c3 += itg;}
    int l1 = c1 * emo * itg, l2 = c2 * phy * itg, l3 = c3 * emo*phy;
    int res = (p*l1 + e*l2 + i*l3) % (emo*phy*itg) - d;
    while(res <= 0) {
        res += emo*phy*itg;
    }
    return res;
}
int main() {
    int p, e, i, d;
    int caseCnt = 0;
    while(cin >> p >> e >> i >> d) {
        caseCnt++;
        if(p == -1 && e == -1 && i == -1 && d == -1) {
            break;
        }
        formatOut(caseCnt, solve(p, e, i, d));
    }
    return 0;
}
