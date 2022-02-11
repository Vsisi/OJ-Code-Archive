#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
vector<int> cp;
map<int, bool> duplicate;
int n;
int maxPos = 0;
void addCriticalPoints(int pos) {
    #ifdef DEBUG
        cout << pos << endl;
    #endif
    for(int i = -1; i <= 1; i++) {
        if(
            pos-n+i >= 1 && 
            duplicate[pos-n+i] == false 
            // (pos-1)/n -1 == (pos-n+i-1)/n
            ) {
            #ifdef DEBUG
                cout << pos-n+i << " ";
            #endif
            duplicate[pos-n+i] = true;
            cp.push_back(pos-n+i);
        }
        #ifdef DEBUG
            cout << endl;
        #endif
        if(
            pos+i >= 1 && 
            duplicate[pos + i] == false
            // (pos-1)/n == (pos+i-1)/n
            ) {
            #ifdef DEBUG
                cout << pos + i << " ";
            #endif
            duplicate[pos + i] = true;
            cp.push_back(pos+i);
        }
        #ifdef DEBUG
            cout << endl;
        #endif
        if(
            pos+n+i >= 1 && 
            duplicate[pos+n+i] == false
            // (pos-1)/n+1 == (pos+i+n-1)/n
            ) {
            #ifdef DEBUG
                cout << pos+n+i << " ";
            #endif
            duplicate[pos+n+i] = true;
            cp.push_back(pos+n+i);
        }
        #ifdef DEBUG
            cout << endl;
        #endif
    }
    #ifdef DEBUG
        cout << "-------------------" << endl;
    #endif
}
vector<pair<int, int>> rle;
int getVal(int pos) {
    int x = 1;
    for(int i = 0; i < rle.size(); i++) {
        if(x + rle[i].second-1 < pos) {
            x += rle[i].second;
        }else {
            return rle[i].first;
        }
    }
}
int calcCode(int pos) {
    int res = -1;
    int val = getVal(pos);
    for(int i = -1; i <= 1; i++) {
        if(pos-n+i >= 1 && pos-n+i <= maxPos && (pos-1)/n -1 == (pos-n+i-1)/n) {
            res = max(res, abs(getVal(pos-n+i) - val));
        }
        if(pos+i >= 1 && pos+i <= maxPos && (pos-1)/n == (pos+i-1)/n) {
            if(i != 0) {
                res = max(res, abs(getVal(pos+i) - val));
            }
        }
        if(pos+n+i >= 1 && pos+n+i <= maxPos && (pos-1)/n + 1 == (pos+i+n-1)/n) {
            res = max(res, abs(getVal(pos+n+i)-val));
        }
    }
    if(res == -1) {
        res = val;
    }
    // #ifdef DEBUG
    //     cout << pos << " " << res << endl;
    // #endif
    return res;
}

void solve() {
    cout << n << endl;
    if(rle.size() != 0) {
        sort(cp.begin(), cp.end());
        int code, lastCode = -1;
        int num = 0;
        int sum = 0;
        for(int i = 0; i < cp.size(); i++) {
            if(cp[i] > maxPos) {
                break;
            }
            code = calcCode(cp[i]);
            if(lastCode == -1) {
                lastCode = code;
                continue;
            }
            if(code == lastCode) {
                num += cp[i] - cp[i-1];
            }else{
                num += cp[i] - cp[i-1];
                cout << lastCode << " " << num << endl;
                sum += num;
                lastCode = code;
                num = 0;
            }
            // #ifdef DEBUG
                // cout << getVal(cp[i]) << " " << cp[i] << " " << code << " " << num << endl;
                // system("pause");
            // #endif
        }
        cout << lastCode << " " << maxPos - sum << endl;
    }
    cout << 0 << " " << 0 << endl;
}
int main() {
    int a, b;
    int pos;
    while(1) {
        rle.clear();
        cp.clear();
        duplicate.clear();
        maxPos = 0;
        pos = 1;
        cin >> n;
        if(n == 0) {
            break;
        }
        while(1) {
            cin >> a >> b;
            if(a == 0 && b == 0) {
                break;
            }
            rle.push_back(pair<int, int>(a, b));
            addCriticalPoints(pos); //start
            addCriticalPoints(pos+b-1); //end
            pos += b;
            maxPos += b;
        }
        solve();
    }
    cout << 0 << endl;
    return 0;
}

/*
思路：
对点编号，采用点的编号代替二维数组坐标，仅在关键点计算该点CODE，非关键点的值与其左边的值相同（这里的左边包括跨行的左边）
关键点指的是一段区间的开始点、结束点及其周边的点，即一个点最多对应9个点（无重复情况下），注意这里9个点需要包括跨行的点（而计算某点CODE时所取的9个点不需要跨行）。
例如，点(x,n)的右下方对应点为(x+1, n+1)，超出了图片（矩阵）范围，此时需要加入(x+1, 1)而非简单舍弃这个点。
*/
