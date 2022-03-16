#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        pq.push(temp);
        if(pq.size() > k) {
            pq.pop();
        }
    }
    cout << pq.top();
    return 0;
}
