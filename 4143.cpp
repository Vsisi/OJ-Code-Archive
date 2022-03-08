#include<bits/stdc++.h>
using namespace std;
int main() {
    map<int, int> exist;
    int n;
    cin >> n;
    int tempNum;
    exist.clear();
    for(int i = 0; i < n; i++) {
        cin >> tempNum;
        exist[tempNum]++;
    }
    int m;
    cin >> m;
    for(map<int, int>::iterator it = exist.begin(); it != exist.end(); it++) {
        if(exist[m-it->first] > 0 && exist[it->first] > 0) {
            if(m-it->first == it->first && exist[it->first]==1) {
                continue;
            }
            cout << it->first << " " << m-it->first;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
