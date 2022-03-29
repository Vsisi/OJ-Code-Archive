#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    int n;
    cin >> n;
    int type, u;
    while(n--) {
        cin >> type;
        if(type == 1) {
            cin >> u;
            pq.push(u);
        }else {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
    return 0;
}
