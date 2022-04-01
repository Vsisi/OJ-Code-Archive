#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int N = 12;
int ans;
int n;
vector<string> dnas;
int overlapLen[N][N];
int calcOverlap(const string& front, const string& back) {
    int len = 0;
    bool flag = true;
    for(int i = 1; i <= min(back.size(), front.size()); i++) {
        flag = true;
        for(int j = 0; j < i; j++) {
            if(front[front.size()-i+j] != back[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            len = i;
        }
    }
    return len;
}
bitset<10> selected;
void solve(string str, int backIdx, int depth) {
    if(depth == n) {
        ans = min(int(str.length()), ans);
        // cout << str << " " << str.length() << endl;
        return;
    }
    if(str.length() >= ans) {
        return;
    }
    string temp;
    for(int i = 0; i < n; i++) {
        if(!selected.test(i)) {
            temp = str;
            for(int j = overlapLen[backIdx][i]; j < dnas[i].size(); j++) {
                temp += dnas[i][j];
            }
            selected.set(i);
            solve(temp, overlapLen[backIdx][i] == dnas[i].size() ? backIdx : i, depth+1);
            selected.reset(i);
        }
    }
}
int main() {
    int t;
    cin >> t;
    string dna;
    vector<string> temp;
    while(t--) {
        ans = INF;
        dnas.clear();
        temp.clear();
        bool noRepeat = true;

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> dna;
            temp.push_back(dna);
        }
        for(int i = 0; i < n; i++) {
            noRepeat = true;
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                if(temp[j].find(temp[i]) != -1) {
                    noRepeat = false;
                    break;
                }
            }
            if(noRepeat) {
                dnas.push_back(temp[i]);
            }
        }
        n = dnas.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                overlapLen[i][j] = calcOverlap(dnas[i], dnas[j]);
            }
        }
        for(int i = 0; i < n; i++) {
            selected = (1<<i);
            solve(dnas[i], i, 1);
        }
        cout << ans << endl;
    }
    return 0;
}
