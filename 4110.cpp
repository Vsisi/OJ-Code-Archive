#include<bits/stdc++.h>
using namespace std;
struct Candy{
    Candy(int price, int weight):price(price), weight(weight) {
        pricePerWeight = price * 1.0 / weight;
    }
    bool operator<(const Candy& other) const {
        return pricePerWeight > other.pricePerWeight;
    }
    int price, weight;
    double pricePerWeight;
};
int main() {
    int n, w;
    cin >> n >> w;
    vector<Candy> v;
    int price, weight;
    for(int i = 0; i < n; i++) {
        cin >> price >> weight;
        v.push_back(Candy(price, weight));
    }
    sort(v.begin(), v.end());
    double res = 0;
    for(int i = 0; i < n; i++) {
        if(w >= v[i].weight) {
            res += v[i].price;
            w -= v[i].weight;
        }else {
            res += w * v[i].pricePerWeight;
            break;
        }
    }
    printf("%.1lf", res);
    return 0;
}
