#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(const string& src, int p1, int p2) {
    while(p1 < p2) {
        if(src[p1] != src[p2]) {
            return false;
        }
        p1++;
        p2--;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    string str;
    while(t--) {
        cin >> str;
        int p1 = 0;
        int len = str.length();
        int cnt = 0;
        while(len > 0) {
            for(int p2 = str.length()-1; p2 >= p1; p2--) {
                if(isPalindrome(str, p1, p2)) {
                    len -= p2 - p1 + 1;
                    p1 = p2 + 1;
                    cnt++;
                }
            }
        }
        cout << cnt-1 << endl;
    }
}
