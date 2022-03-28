#include<bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int mat[MAXN][MAXN];
int matTemp[MAXN][MAXN];
int n;
void rotate90() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matTemp[j][n-1-i] = mat[i][j];
            // cout << i << " " << j << " " << j << " " << n-i << endl;
            // system("pause");
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mat[i][j] = matTemp[i][j];
        }
    }
}
int main() {
    int m;
    cin >> m;
    while(m--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        rotate90();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j < n-1) {
                    cout << mat[i][j] << " ";
                }else {
                    cout << mat[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
