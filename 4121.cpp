#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n, price;
    vector<int> prices;
    while(t--) {
        cin >> n;
        prices.clear();
        for(int i = 0; i < n; i++) {
            cin >> price;
            prices.push_back(price);
        }
        int buy1, buy2, sell1, sell2;
        buy1 = -prices[0]; buy2 = -prices[0];
        sell1 = 0; sell2 = 0;
        for(int i = 1; i < n; i++) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1-prices[i]);
            sell2 = max(sell2, prices[i] + buy2);
        }
        cout << sell2 << endl;
    }
    return 0;
}
