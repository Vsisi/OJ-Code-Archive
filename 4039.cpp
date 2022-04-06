#include<bits/stdc++.h>
using namespace std;
int string2Int(string str) {
    stringstream ss;
    int n;
    ss << str;
    ss >> n;
    return n;
}
void print(string str) {
    str += '.';
    string now = "";
    vector<bitset<8>> v;
    for(auto c:str) {
        if(isdigit(c)) {
            now += c;
        }else {
            v.push_back(bitset<8>(string2Int(now)));
            now = "";
        }
    }
    for(auto b:v) {
        cout << b.to_string();
    }
    cout << endl;
}
int main() {
    string str;
    while(cin >> str) {
        if(str == "-1") {
            break;
        }
        print(str);
    }
    return 0;
}
