#include<bits/stdc++.h>
using namespace std;
struct Fruit{
    Fruit(int id, int a, int b):id(id), a(a), b(b), val(a+b) {

    }
    bool operator<(const Fruit& other) const {
        return val < other.val;
    }
    bool operator>(const Fruit& other) const {
        return val > other.val;
    }
    int id, a, b, val;
};
priority_queue<Fruit, vector<Fruit>, greater<Fruit>> pq;
int main() {
    int m, n;
    cin >> m;
    int id, a, b;
    while(m--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> id >> a >> b;
            pq.push(Fruit(id, a, b));
            if(pq.size() > 2) {
                pq.pop();
            }
        }
        cout << pq.top().id << " " << pq.top().a << " " << pq.top().b << " " << pq.top().val << endl;
        while(pq.size()) {
            pq.pop();
        }
    }
}
