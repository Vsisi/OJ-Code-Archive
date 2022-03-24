#include<bits/stdc++.h>
using namespace std;
map<char, string> hex2bin;
void init() {
    hex2bin['0'] = "0000"; hex2bin['1'] = "0001"; hex2bin['2'] = "0010";
    hex2bin['3'] = "0011"; hex2bin['4'] = "0100"; hex2bin['5'] = "0101";
    hex2bin['6'] = "0110"; hex2bin['7'] = "0111"; hex2bin['8'] = "1000";
    hex2bin['9'] = "1001"; hex2bin['a'] = "1010"; hex2bin['b'] = "1011";
    hex2bin['c'] = "1100"; hex2bin['d'] = "1101"; hex2bin['e'] = "1110";
    hex2bin['f'] = "1111";
}
string hex2BinFunc(string hexStr) {
    string res = "";
    for(auto c:hexStr) {
        res += hex2bin[c];
    }
    return res;
}
int calc1Block(string binStr) {
    int res = 0;
    int i = 0;
    while(i < binStr.size()) {
        if(binStr[i] == '1') {
            res++;
            // cout << i << " ";
            while(i < binStr.size() && binStr[i] == '1') {
                i++;
            }
        }
        while(i < binStr.size() && binStr[i] == '0') {
            i++;
        }
    }
    // cout << endl;
    return res;
}
void solve(string bob, string alice) {
    string bobBin = hex2BinFunc(bob), aliceBin = hex2BinFunc(alice);
    int bob1s = calc1Block(bobBin), alice1s = calc1Block(aliceBin);
    if(bob1s < alice1s) {
        cout << "Alice" << endl;
    }else if(bob1s > alice1s) {
        cout << "Bob" << endl;
    }else {
        cout << "Tie" << endl;
    }

}
int main() {
    init();
    int n;
    cin >> n;
    string bob, alice;
    while(n--) {
        cin >> alice >> bob;
        solve(bob.substr(2, bob.size() - 2), alice.substr(2, alice.size() - 2));
    }
    return 0;
}
