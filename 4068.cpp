#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int str2int(string str) {
    stringstream ss;
    int res;
    ss << str;
    ss >> res;
    return res;
}
void spilt(const string& line) {
    string temp = "";
    for(auto c:line) {
        if(c != ' ') {
            temp += c;
            continue;
        }
        if(temp != "") {
            v.push_back(str2int(temp));
        }
        temp = "";
    }
    if(temp != "") {
        v.push_back(str2int(temp));
    }
}
int main() {
    int n;
    cin >> n;getchar();
    string line;
    while(n--) {
        v.clear();
        getline(cin, line);
        spilt(line);
        sort(v.begin(), v.end());
        if(v.size() <= 2) {
            cout << "True" << endl;
        }else { 
            int diff = v[1] - v[0];
            bool flag = true;
            for(int i = 1; i < v.size() - 1; i++) {
                if(v[i+1] - v[i] != diff) {
                    flag = false;
                    break;
                }
            }
            cout << (flag ? "True" : "False") << endl;
        }
    }
    return 0;
}
