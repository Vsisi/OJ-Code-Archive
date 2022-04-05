#include<bits/stdc++.h>
using namespace std;
const int MAXK = 55;
struct Inn{
    Inn(int color, int cost):color(color), cost(cost) {}
    int color;
    int cost;
};
vector<int> innBatch[MAXK];
set<int> colors;
int main() {
    int n, k, p;
    cin >> n >> k >> p;
    int tmpColor, tmpCost;
    vector<Inn> inns;
    for(int i = 0; i < n; i++) {
        cin >> tmpColor >> tmpCost;
        inns.push_back(Inn(tmpColor, tmpCost));
        colors.insert(tmpColor);
    }
    int ans = 0;
    int ok = 0;
    int pending = 0;
    for(auto color:colors) {
        ok = 0;
        pending = 0;
        for(auto inn:inns) {
            if(pending && inn.cost <= p) {
                ok += pending;
                pending = 0;
            }
            if(inn.color == color) {
                ans += ok;
                if(inn.cost <= p) {
                    ok++;
                }else {
                    pending++;
                }
            }
            // cout << ok << " " << pending << endl;
        }
        // cout << endl;
        // cout << ans << endl;
    }
    cout << ans;
    return 0;
}
