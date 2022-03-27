#include<bits/stdc++.h>
using namespace std;
const string NO_DOC = "NOT FOUND";
const int WORDS = 110;
unordered_map<int, bool> word[WORDS]; 
void intersect(unordered_map<int, bool>& wd, unordered_map<int, bool>& res) {
    vector<int> temp; temp.clear();
    for(unordered_map<int, bool>::iterator it = wd.begin(); it != wd.end(); it++) {
        if(wd[it->first] && res[it->first]) {
            temp.push_back(it->first);
        }
    }
    res.clear();
    for(auto i:temp) {
        res[i] = true;
    }
}
void diff(unordered_map<int, bool>& wd, unordered_map<int, bool>& res) {
    vector<int> temp; temp.clear();
    for(unordered_map<int, bool>::iterator it = res.begin(); it != res.end(); it++) {
        if(res[it->first] && !wd[it->first]) {
            temp.push_back(it->first);
        }
    }
    res.clear();
    for(auto i:temp) {
        res[i] = true;
    }
}
int main() {
    int n;
    int c;
    int did;
    cin >> n;
    set<int> dids;
    for(int wid = 0; wid < n; wid++) {
        cin >> c;
        for(int i = 0; i < c; i++) {
            cin >> did;
            dids.insert(did);
            word[wid][did] = true;
        }
    }
    int m;
    cin >> m;
    int require;
    while(m--) {
        unordered_map<int, bool> res;
        for(auto did:dids) {
            res[did] = true;
        }
        for(int wid = 0; wid < n; wid++) {
            cin >> require;
            if(require == 0) {
                continue;
            }else if(require == 1) {
                intersect(word[wid], res);
            }else {//-1
                diff(word[wid], res);
            }
        }
        vector<int> temp;
        for(unordered_map<int, bool>::iterator it = res.begin(); it != res.end(); it++) {
            if(it->second) {
                temp.push_back(it->first);
            }
        }
        sort(temp.begin(), temp.end());
        if(!temp.empty()) {
            for(auto did:temp) {
                cout << did << " ";
            }
        }else {
            cout << NO_DOC;
        }
        cout << endl;
    }
    return 0;
}
