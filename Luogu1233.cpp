#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
struct Stick {
    Stick(int w, int l):w(w), l(l) {}
    bool operator<(const Stick& rhs) const {
        if(w != rhs.w) {
            return w > rhs.w;
        }
        return l > rhs.l;
    }
    int w, l;
};
vector<vector<int>> decSeqs;
int main() {
    int n;
    int tmpW, tmpL;
    vector<Stick> sticks;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmpW >> tmpL;
        sticks.push_back(Stick(tmpW, tmpL));
    }
    sort(sticks.begin(), sticks.end());
    bool geThanAll;
    int maxn;
    int tgtJ;
    vector<int> tmp;
    for(int i = 0; i < n; i++) {
        geThanAll = true;
        maxn = 1e6;
        for(int j = 0; j < decSeqs.size(); j++) {
            if(maxn > decSeqs[j].back() && decSeqs[j].back() >= sticks[i].l) {
                maxn = decSeqs[j].back();
                tgtJ = j;
                geThanAll = false;
            }
        }
        if(geThanAll) {
            tmp.clear();
            tmp.push_back(sticks[i].l);
            decSeqs.push_back(tmp);
        }else {
            decSeqs[tgtJ].push_back(sticks[i].l);
        }
    }
    // for(auto seq:decSeqs) {
    //     for(auto item:seq) {
    //         cout << item << " ";
    //     }
    //     cout << endl;
    // }
    cout << decSeqs.size();
    return 0;
}
