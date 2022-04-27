#include<bits/stdc++.h>
using namespace std;
vector<int> permutation;
int main() {
    int n, m;
    int temp;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        permutation.push_back(temp);
    }
    for(int i = 0; i < m; i++) {
        next_permutation(permutation.begin(), permutation.end());
    }
    for(auto entry:permutation) {
        cout << entry << " ";
    }
    return 0;
}
