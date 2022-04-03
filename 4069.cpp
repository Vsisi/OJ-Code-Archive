#include<bits/stdc++.h>
using namespace std;
struct Cellphone {
    Cellphone(int id, int price, int sellNum, int avgScore):id(id), price(price), sellNum(sellNum), avgScore(avgScore) {}
    bool operator<(const Cellphone& rhs) const {
        if(this->sellNum != rhs.sellNum) {
            return this->sellNum > rhs.sellNum;
        }else {
            if(this->avgScore != rhs.avgScore) {
                return this->avgScore > rhs.avgScore;
            }else {
                return this->price < rhs.price;
            }
        }
    }
    int id, price, avgScore, sellNum;
};
int main() {
    int m;
    cin >> m;
    int k, n;
    int id, price, sn, as;
    vector<Cellphone> cellphones;
    while(m--) {
        cellphones.clear();
        cin >> k >> n;
        for(int i = 0; i < n; i++) {
            cin >> id >> price >> sn >> as;
            cellphones.push_back(Cellphone(id, price, sn, as));
        }
        sort(cellphones.begin(), cellphones.end());
        for(auto cellphone:cellphones) {
            if(k >= cellphone.price) {
                cout << cellphone.id << endl;
            }
        }
    }
    return 0;
}
