#include<bits/stdc++.h>
using namespace std;
const int MAXM = 25;
const int MAXN = 15;
int score[MAXM][MAXN];
int sumRow[MAXM], sumCol[MAXN];
int numRow[MAXM], numCol[MAXN];
int d[MAXN];
int main() {
    int m, n;
    cin >> m >> n;
    vector<string> courseNames;
    string tempName;
    for(int i = 0; i < n; i++) {
        cin >> tempName;
        courseNames.push_back(tempName);
    }
    int sum;
    int cnt;
    for(int i = 0; i < m; i++) {
        sum = 0;
        cnt = 0;
        for(int j = 0; j < n; j++) {
            cin >> score[i][j];
            sum += score[i][j];
            if(score[i][j] != 0) {
                cnt++;
            }
        }
        sumRow[i] = sum;
        numRow[i] = cnt;
    }
    for(int j = 0; j < n; j++) {
        sum = 0;
        cnt = 0;
        for(int i = 0; i < m; i++) {
            sum += score[i][j];
            if(score[i][j] != 0) {
                cnt++;
            }
        }
        sumCol[j] = sum;
        numCol[j] = cnt;
    }
    for(int j = 0; j < n; j++) {
        sum = 0;
        cnt = 0;
        for(int i = 0; i < m; i++) {
            if(score[i][j] != 0) {
                sum += sumRow[i];
                cnt += numRow[i];
            }
        }
        d[j] = sum / cnt - sumCol[j] / numCol[j];
    }
    for(int i = 0; i < n; i++) {
        cout << courseNames[i] << " " << d[i] << endl;
    }
    return 0;
}
