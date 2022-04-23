#include<bits/stdc++.h>
using namespace std;
const int MAXN = 520;
const int INF = 0x3fffffff;
int mat[MAXN][MAXN] = {0};
int calcMax(int* arr, int len) {
    int res = arr[0];
    int curSum = arr[0];
    for(int i = 1; i < len; i++) {
        if(curSum < 0) {
            curSum = 0;
        }
        curSum += arr[i];
        res = max(curSum, res);
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    int res = -INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
        res = max(res, calcMax(mat[i], n));
    }
    int arr[MAXN];
    for(int i = 0;  i < n-1; i++) {
        for(int j = 0; j < n; j++) {
            arr[j] = mat[i][j];
        }
        for(int j = i+1; j < n; j++) {
            for(int k = 0; k < n; k++) {
                arr[k] += mat[j][k];
            }
            res = max(res, calcMax(arr, n));
        }
    }
    cout << res;
    return 0;
}
