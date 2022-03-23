#include<bits/stdc++.h>
using namespace std;
bool judge(int p) {
    stringstream ss;
    string s;
    ss << p;
    ss >> s;
    for(int i = 0; i < s.length()-1; i++) {
        if(s[i] == '1' && s[i+1] == '9') {
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    int price;
    while(n--) {
        cin >> price;
        if(price % 19 == 0 || judge(price)) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }
    return 0;
}
