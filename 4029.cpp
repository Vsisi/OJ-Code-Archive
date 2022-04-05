#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    stringstream  ss;
    string str;
    bool negative = false;
    if(n < 0) {
        negative = true;
    }
    n = abs(n);
    ss << n;
    ss >> str;
    reverse(str.begin(), str.end());
    int i = 0;
    while(str[i] == '0') {
        i++;
    }
    if(negative) {
        cout << "-";
    }
    for(int j = i; j < str.size(); j++) {
        cout << str[j];
    }
    return 0;
}
