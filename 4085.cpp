#include<bits/stdc++.h>
using namespace std;
int main() {
    set<int> s;
    int n, num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        s.insert(num);
    }
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}
