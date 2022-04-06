#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    vector<int> v;
    int tmp;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        v.clear();
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        if(n % 2 == 0) { //even
            cout << ((v[n/2-1] + v[n/2]) >> 1) << endl;
        }else { //odd
            cout << v[n/2] << endl;
        }
    }
    return 0;
}
