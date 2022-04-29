#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1e2;
map<int, int> mapping;
int arr2[MAXN];
vector<int> monoStack;
int main() {
    int n;
    cin >> n;
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        mapping[tmp] = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> arr2[i];
        arr2[i] = mapping[arr2[i]];
    }
    for(int i = 0; i < n; i++) {
        if(monoStack.empty() || arr2[i] > monoStack.back()) {
            monoStack.push_back(arr2[i]);
        }else {
            *upper_bound(monoStack.begin(), monoStack.end(), arr2[i]) = arr2[i];
        }
    }
    cout << monoStack.size();
    return 0;
}
