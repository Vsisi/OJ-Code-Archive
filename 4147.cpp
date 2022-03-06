#include<bits/stdc++.h>
using namespace std;
void hanoi(char src, char dst, char mid, int num, int top) {
    if(num == 1) {
        printf("%d:%c->%c\n", top, src, dst);
        return;
    }
    hanoi(src, mid, dst, num-1, 1);
    hanoi(src, dst, mid, 1, num);
    hanoi(mid, dst, src, num-1, 1);
}   
int main() {
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    int top = 1;
    hanoi(a, c, b, n, 1);
    return 0;
}
