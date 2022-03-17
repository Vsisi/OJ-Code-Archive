#include<bits/stdc++.h>
using namespace std;
map<char, char> dict;
int main() {
    string signal;
    dict['A'] = '1';dict['B'] = '2';dict['C'] = '$';dict['D'] = '\n';
    cin >> signal;
    for(auto c:signal) {
        cout << dict[c];
    }
    return 0;
}
