#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
int getMaxRes(const vector<int>& v1, const vector<int>& v2) {
    int res = 0;
    int v1s, v1e, v2s, v2e;
    int n = v1.size();
    v1s = v2s = 0;
    v1e = v2e = v1.size() - 1;
    for(int i = 0; i < n; i++) {
        if(v1[v1s] > v2[v2s]) { // win 
            v1s++;
            v2s++;
            res += 3;
        }else if(v2[v2s] > v1[v1s]) {//lose
            v2s++;
            v1e--;
            res += 1;
        }else { //even
            if(v1[v1e] > v2[v2e]) {
                v1e--;
                v2e--;
                res += 3;
            }else {
                if(v1[v1e] < v2[v2s]) {
                    res += 1;
                }else {
                    res += 2;
                }
                v1e--;
                v2s++;
            }
        }
    }
    return res;
}
int main() {
    int n;
    int tmpVal;
    vector<int> tianji, king;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        tianji.clear();
        king.clear();
        for(int i = 0; i < n; i++) {
            cin >> tmpVal;
            king.push_back(tmpVal);
        }
        for(int i = 0; i < n; i++) {
            cin >> tmpVal;
            tianji.push_back(tmpVal);
        }
        sort(tianji.begin(), tianji.end(), greater<int> ());
        sort(king.begin(), king.end(), greater<int> ());
        cout << getMaxRes(tianji, king) << " " << 4 * n - getMaxRes(king, tianji) << endl; 
    }
    return 0;
}
