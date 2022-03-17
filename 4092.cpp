#include<bits/stdc++.h>
using namespace std;
const string NO_SOLUTION = "no significant commonalities";
const int LEN = 60;
int main() {
    int n;
    cin >> n;
    int m;
    string dna;
    vector<string> v;
    while(n--) {
        cin >> m;
        v.clear();
        for(int i = 0; i < m; i++) {
            cin >> dna;
            v.push_back(dna);
        }
        int p = 0;
        string substring;
        bool flag = true;
        bool hasSolution = false;
        vector<string> solution;
        for(int offset = LEN; offset >= 3; offset--) {
            p = 0;
            solution.clear();
            while(p + offset <= LEN) {
                flag = true;
                substring = v[0].substr(p, offset);
                for(int i = 1; i < v.size(); i++) {
                    if(v[i].find(substring) == -1) {
                        flag = false;
                        break;
                    }
                }
                p++;
                if(flag) {
                    solution.push_back(substring);
                }
            }
            
            if(solution.size() > 0) {
                hasSolution = true;
                sort(solution.begin(), solution.end());
                cout << solution[0] << endl;
                break;
            }
        }
        if(!hasSolution) {
            cout << NO_SOLUTION << endl;
        }
    }
    return 0;
}
