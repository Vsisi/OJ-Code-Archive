#include<bits/stdc++.h>
using namespace std;
const int N = 110;
bool friRe[N][N];
void yieldCase() {
    static int caseNum = 1;
    printf("Case %d:\n", caseNum++);
}
int main() {
    int c;
    cin >> c;
    int n, m, k;
    int a, b;
    while(c--) { 
        cin >> n >> m >> k;
        memset(friRe, false, sizeof(friRe));
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            friRe[a][b] = true;
            friRe[b][a] = true;
        }
        int cnt = 0;
        yieldCase();
        for(int ki = 0; ki < k; ki++) {
            cnt = 0;
            cin >> a >> b;
            for(int i = 1; i <= n; i++) {
                if(i == a || i == b) {
                    continue;
                }
                if(friRe[a][i] && friRe[i][b]) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
