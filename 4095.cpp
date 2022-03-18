#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string str;
    int caps;
    bool capFlag = false;
    for(int i = 0; i < n; i++) {
        caps = 0;
        capFlag = false;
        cin >> str;
        for(auto c:str) {
            if(isupper(c) && !capFlag) {
                capFlag = true;
                caps++;
            }else if(islower(c) && capFlag) {
                capFlag = false;
                caps++;
            }
        }
        cout << caps + str.length() << endl;
    }
    return 0;
}
