#include<bits/stdc++.h>
using namespace std;
void solve(string str) {
    map<char, int> m;
    m.clear();
    for(auto c:str) {
        m[c]++;
    }
    for(auto c:str) {
        if(m[c] == 2) {
            cout << c << endl;
            return;
        }
    }
}
int main() {
    int n;
    string str;
    cin >> n;
    while(n--) {
        cin >> str;
        solve(str);
    }
    return 0;
}
