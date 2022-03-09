#include<bits/stdc++.h>
using namespace std;
long long decompose(long long n, int pos) {
    stringstream ss;
    string str;
    ss << n;
    ss >> str;
    long long res;
    string temp = "";
    for(int i = 0; i < str.length(); i++) {
        if(i != pos) {
            temp += str[i];
        }
    }
    ss.clear();
    ss << temp;
    ss >> res;
    return res;
}
int getLen(long long n) {
    stringstream ss;
    string str;
    ss << n;
    ss >> str;
    return str.length();
}
long long delOne(long long n) {
    int len = getLen(n);
    long long res = LLONG_MAX;
    for(int i = 0; i < len; i++) {
        res = min(res, decompose(n, i));
    }
    return res;

}
int main() {
    int t;
    cin >> t;
    long long res, k;
    while(t--) {
        cin >> res >> k;
        for(int i = 0; i < k; i++) {
            res = delOne(res);
        }
        cout << res << endl;
    }
    return 0;
}
