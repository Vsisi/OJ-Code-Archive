#include<bits/stdc++.h>
using namespace std;
struct Interval{
    Interval(int s, int d):s(s), d(d) {}
    bool operator<(const Interval& other) const {
        if(s != other.s) {
            return d < other.d;
        }
        return s < other.s;
    }
    int s, d;
};
int main() {
    int k;
    cin >> k;
    int n;
    vector<Interval> v;
    int s, d;
    int res = 0;
    int j;
    while(k--) {
        res = 0;
        v.clear();
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> s >> d;
            v.push_back(Interval(s, d));
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; ) {
            res++;
            for(j = i; j < n; j++) {
                if(v[j].s > v[i].d) {
                    break;
                }
            }
            i = j;
        }
        cout << res << endl;
    }
    return 0;
}
