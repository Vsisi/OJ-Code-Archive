#include<bits/stdc++.h>
using namespace std;
bool judgePalindrom(int n) {
    stringstream ss;
    string str1, str2;
    ss << n;
    ss >> str1;
    str2 = str1;
    reverse(str2.begin(), str2.end());
    return str1 == str2;
}
int main() {
    int n;
    while(cin >> n) {
        if(judgePalindrom(n)) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
