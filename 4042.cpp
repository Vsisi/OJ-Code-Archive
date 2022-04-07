#include<bits/stdc++.h>
using namespace std;
int getID(char c) {
    return c - 'a' + 1;
}
int main() {
    int n;
    cin >> n;
    string s;
    int m, q;
    vector<string> res;
    int cnt = 0;
    while(n--) {
        cnt = 0;
        res.clear();
        
        cin >> s >> m >> q;
        for(int i = 0; i < s.size(); i++) {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                sum += getID(s[j+i]);
            }
            if(sum == q) {
                cnt++;
                res.push_back(s.substr(i, m));
            }
        }
        cout << cnt << endl;
        for(auto r:res) {
            cout << r << endl;
        }
    }
    return 0;
}
