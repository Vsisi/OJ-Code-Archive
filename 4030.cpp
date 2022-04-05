#include<bits/stdc++.h>
using namespace std;
string toLowerStr(string str) {
    string res;
    res.clear();
    for(int i = 0; i < str.length(); i++) {
        if(!isalpha(str[i])) {
            break;
        }
        res.push_back(tolower(str[i]));
    }
    return res;
}
int main() {
    string word, sentence;
    int tot = 0;
    int first = -1;
    int cnt = 0;
    string sWord;
    int idx = 0;
    getline(cin, word);
    word = toLowerStr(word);
    getline(cin, sentence);
    while(idx < sentence.size()) {
        while(idx < sentence.size() && !isalpha(sentence[idx])) {
            idx++;
        }
        if(idx >= sentence.size()) {
            break;
        }
        sWord = "";
        while(idx < sentence.size() && isalpha(sentence[idx])) {
            sWord += sentence[idx++];
        }
        if(toLowerStr(sWord) == word) {
            tot++;
            if(first == -1) {
                first = idx - sWord.size();
            }
        }
    }
    if(first != -1)
        cout << tot << " " << first;
    else
        cout << -1;
    return 0;
}
