#include<bits/stdc++.h>
using namespace std;
string decode(string word, int idx) {
    string ans = "";
    reverse(word.begin(), word.end());
    int tmp;
    for(auto c:word) {
        
        if(isupper(c)) {
            ans += 'A' + (c-'A'-idx + 26) % 26;
        }else { 
            ans+= 'a' + (c-'a'-idx + 26) % 26;
        }
    }
    return ans;
}
int main() {
    string str;
    while(getline(cin, str)) {
        int p = 0;
        int idx = 1;
        string word = "";
        while(p < str.length()) {
            if(isalpha(str[p])) {
                word = "";
                while(p < str.length() && isalpha(str[p])) {
                    word += str[p];
                    p++;
                }
                cout << decode(word, idx++);
            }
            while(p < str.length() && !isalpha(str[p])) {
                cout << str[p];
                p++;
            }
        }
        cout << endl;
    }
    return 0;
}
