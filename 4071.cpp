#include<bits/stdc++.h>
using namespace std;
void splitOrgStr(const string& orgStr, string& str, int& k) {
    string strK = "";
    int i;
    for(i = orgStr.length(); i >= 0; i--) {
        if(orgStr[i] == ' ') {
            break;
        }
        strK += orgStr[i];
    }
    str = orgStr.substr(0, i);
    reverse(strK.begin(), strK.end());
    stringstream ss;
    ss << strK;
    ss >> k;
}
map<char, int> mem;
int main() {
    int n;
    string orgStr, str;
    int k;
    cin >> n; getchar();
    vector<char> res;
    while(n--) {
        mem.clear();
        res.clear();

        getline(cin, orgStr);
        splitOrgStr(orgStr, str, k);
        for(auto c:str) {
            mem[c]++;
        }
        for(map<char, int>::iterator it = mem.begin(); it != mem.end(); it++) {
            if(it->second == k) {
                res.push_back(it->first);
            }
        }
        sort(res.begin(), res.end());

        for(int i = 0; i < res.size(); i++) {
            if(i != res.size() - 1) {
                printf("\'%c\',", res[i]);
            }else {
                printf("'%c'", res[i]);
            }
        }
        cout << endl;
    }
    return 0;
}
