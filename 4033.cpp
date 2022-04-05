#include<bits/stdc++.h>
using namespace std;
struct Carpet{
    Carpet(int id, int blX, int blY, int trX, int trY):id(id), blX(blX), blY(blY), trX(trX), trY(trY) {} 
    bool internal(int x, int y) {
        return x >= blX && x <= trX && y >= blY && y <= trY;
    }
    int id;
    int blX, blY, trX, trY;
};
int main() {
    int n;
    cin >> n;
    int a, b, g, k;
    vector<Carpet> carpets;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> g >> k;
        carpets.push_back(Carpet(i+1, a, b, a+g, b+k));
    }
    cin >> a >> b;
    int id = -1;
    for(auto carpet:carpets) {
        if(carpet.internal(a, b)) {
            id = carpet.id;
        }
    }
    cout << id;
    return 0;
}
