#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
int arr[MAXN];
int main() {
    int n;
    int len;
    scanf("%d", &n);
    len = n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    int m;
    scanf("%d", &m);
    string op;
    int x, y, z;
    int minn;
    int nowVal, nextVal;
    int nowIdx;
    int nextIdx;
    int initIdx;
    while(m--) {
        cin >> op;
        if(op == "ADD") {
            scanf("%d%d%d", &x, &y, &z);
            if(y > len) {
                continue;
            }
            for(int i = x; i <= y; i++) {
                arr[i] += z;
            }
        }else if(op == "REVERSE") {
            scanf("%d%d", &x, &y);
            if(y > len) {
                continue;
            }
            for(int i = x; i <= (x+y) >> 1; i++) {
                swap(arr[i], arr[y-(i-x)]);
            }
        }else if(op == "REVOLVE") {
            scanf("%d%d%d", &x, &y, &z);
            if(y > len) {
                continue;
            }
            int iLen = y-x+1;
            if(z >= iLen) {
                z %= iLen;
            }
            if(z == 0 || y > len) {
                continue;
            }
            initIdx = x;
            nowIdx = x;
            nowVal = arr[nowIdx];
            for(int i = 0; i < iLen; i++) {
                nextIdx = nowIdx + z > y ? nowIdx + z - iLen : nowIdx + z;
                nextVal = arr[nextIdx];
                arr[nextIdx] = nowVal;
                nowVal = nextVal;
                nowIdx = nextIdx;
                if(initIdx == nowIdx) {
                    initIdx = ++nowIdx;
                    nowVal = arr[nowIdx];
                }
                // for(int kk = 1; kk <= len; kk++) {
                //     cout << arr[kk] << " ";
                // }
                // cout << endl;
            }
        }else if(op == "INSERT") {
            scanf("%d%d", &x, &y);
            len++;
            for(int i = len; i > x+1; i--) {
                arr[i] = arr[i-1];
            }
            arr[x+1] = y;
        }else if(op == "DELETE") {
            scanf("%d", &x);
            if(len == 0) {
                continue;
            }
            len--;
            for(int i = x; i <= len; i++) {
                arr[i] = arr[i+1];
            }
        }else if(op == "MIN") {
            scanf("%d%d", &x, &y);
            if(y > len) {
                continue;
            }
            minn = INT32_MAX;
            for(int i = x; i <= y; i++) {
                minn = min(minn, arr[i]);
            }
            printf("%d\n", minn);
        }
        // for(int kk = 1; kk <= len; kk++) {
        //     cout << arr[kk] << " ";
        // }
        // cout << endl;
    }
    return 0;
}
