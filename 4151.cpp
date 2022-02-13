#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int>& x, const pair<int, int>& y) {
    return x.second < y.second;
}
int main() {
    int n;
    vector<pair<int, int>> v;
    while(1) {
        v.clear();
        cin >> n;
        if(n == 0) {
            break;
        }
        int a, b;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            v.push_back(pair<int, int>(a, b));
        }
        int latest = 0;
        int cnt = 0;
        sort(v.begin(), v.end(), cmp);
        for(auto event:v) {
            if(event.first >= latest) {
                cnt++;
                latest = event.second;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
