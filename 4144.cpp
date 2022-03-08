#include<bits/stdc++.h>
using namespace std;
struct Interval{
    Interval(double l, double r, int id):l(l), r(r), id(id) {}
    bool operator<(const Interval& other) {
        return this->l < other.l;
    }
    double l, r;
    int id;
};
struct Box{
    Box(vector<Interval> box, int id):id(id) {
        this->box = box;
    }
    bool operator<(const Box& other) const {
        double maxR1 = -1, maxR2 = -1;
        for(auto item:box) {
            maxR1 = max(maxR1, item.r);
        }
        for(auto item:other.box) {
            maxR2 = max(maxR2, item.r);
        }
        return maxR1 > maxR2;
    }
    Box& operator=(const Box& other) {
        this->box = other.box;
        this->id = other.id;
        return *this;
    }
    void removeExpire(double nowTime) {
        for(vector<Interval>::iterator it = box.begin(); it != box.end(); it++) {
            if(it->r < nowTime) {
                box.erase(it);
                if(it == box.end()) {
                    break;
                }
            }
        }
    }
    bool hasIntersect(const Interval& i1, const Interval& i2) {
        return !(i1.r < i2.l || i2.r < i1.l); 
    }
    bool isCompatible(const Interval& cow) {
        if(box.size() == 0) {
            return true;
        }
        for(auto item:box) {
            if(!hasIntersect(cow, item)) {
                return true;
            }
        }
        return false;
    }
    vector<Interval> box;
    int id;
};
int idDistributed[50505] = {0};
priority_queue<Box> pq;
int main() {
    int n;
    cin >> n;
    vector<Interval> v;
    double a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(Interval(a, b, i));
    }
    sort(v.begin(), v.end());
    bool compatible = false;
    int boxId = 1;
    for(auto cow:v) {
        compatible = false;
        if(!pq.empty()) {
            Box temp = pq.top();
            pq.pop();
            temp.removeExpire(cow.l);
            if(temp.isCompatible(cow)) {
                temp.box.push_back(cow);
                idDistributed[cow.id] = temp.id;
                compatible = true;
            }
            pq.push(temp);
        }

        if(!compatible) { //all are not compatible, add new box
            vector<Interval> temp;
            temp.push_back(cow);
            pq.push(Box(temp, boxId));
            idDistributed[cow.id] = boxId++;
        }
    }
    cout << pq.size() << endl;
    for(int i = 0; i < n; i++) {
        cout << idDistributed[i] << endl;
    }
    return 0;
}
