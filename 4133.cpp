#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1025; 
int trash[SIZE][SIZE];
void fill(int x, int y, int d, int trashAmt) {
    int lbx = max(x-d, 0), lby = max(y-d, 0);
    int rtx = min(x+d, 1024), rty = min(y+d, 1024);
    for(int i = lbx; i <= rtx; i++) {
        for(int j = lby; j <= rty; j++) {
            trash[i][j] += trashAmt;
        }
    }
}
int main() {
    int d, n;
    cin >> d >> n;
    int x, y, trashAmt;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> trashAmt;
        fill(x, y, d, trashAmt);
    }
    int maxn = -1;
    int cnt = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(trash[i][j] > maxn) {
                maxn = trash[i][j];
                cnt = 1;
            }else if(trash[i][j] == maxn) {
                cnt++;
            }
        }
    }
    cout << cnt << " " << maxn;
    return 0;
}
