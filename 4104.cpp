#include<bits/stdc++.h>
using namespace std;
int main() {
    string str = "";
    char c;
    while(c = getchar()) {
        if(c == ' ' || c == '\n' || c == EOF) {
            reverse(str.begin(), str.end());
            if(c == EOF || c == '\n') {
                cout << str << endl;
                break;
            }
            cout << str << " ";
            str = "";
        }else {
            str.push_back(c);
        }
    }
    return 0;
}
