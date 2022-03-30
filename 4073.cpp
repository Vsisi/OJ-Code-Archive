#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
int main() {
    int n;
    vector<string> strs;
    string str;
    int minLen, p;
    string postfix;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        minLen = INF;
        p = 0;
        postfix = "";
        bool flag = true;
        strs.clear();

        while(n--) {
            cin >> str;
            minLen =  min(minLen, int(str.size()));
            reverse(str.begin(), str.end());
            strs.push_back(str);
        }

        while(p < minLen) {
            char now = strs[0][p];
            for(int i = 1; i < strs.size(); i++) {
                if(now != strs[i][p]) {
                    flag = false;
                    break;
                }
            }
            if(!flag) {
                break;
            }
            p++;
        }
        if(p == 0) {
            if(flag) {
                postfix = strs[0][0];
            }else {
                postfix = "";
            }
        }else {
            postfix = strs[0].substr(0, p);
            reverse(postfix.begin(), postfix.end());
        }
        cout << postfix << endl;
    }
    return 0;
}
