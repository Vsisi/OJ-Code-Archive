#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll query(ll dst, const vector<ll>& arr) {
    int l = 0, r = arr.size() - 1;
    while(r-l > 1) {
        int mid = (l+r) >> 1;
        if(dst > arr[mid]) {
            l = mid;
        }else if(dst < arr[mid]) {
            r = mid;
        }else {
            return arr[mid]; //dst == arr[mid], must be closest
        }
    }
    return dst - arr[l] <= arr[r] - dst ? arr[l] : arr[r];
}
int main() {
    int n;
    cin >> n;
    ll temp;
    vector<ll> arr;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        cout << query(temp, arr) << endl;
    }
    return 0;
}
