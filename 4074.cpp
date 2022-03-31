#include<bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin >> m;
    int n;
    int height;
    vector<int> heights;
    long long ans = 0;
    int maxn = 0;
    int sum = 0;
    while(m--) {
        ans = 0;
        sum = 0;
        maxn = 0;
        heights.clear();
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> height;
            maxn = max(height, maxn);
            sum += height;
            heights.push_back(height);
        }
        int maxnPos1 = 0, maxnPos2 = 0;
        for(int i = 0; i < n; i++) {
            if(heights[i] == maxn) {
                maxnPos1 = i;
                break;
            }
        }
        for(int i = n-1; i >= 0; i--) {
            if(heights[i] == maxn) {
                maxnPos2 = i;
                break;
            }
        }
        int nowMax = heights[0], nowPos = 0;
        int area1 = 0, area2 = 0;
        for(int i = 0; i <= maxnPos1; i++) {
            if(heights[i] > nowMax) {
                area1 += (i - nowPos) * nowMax;
                nowMax = heights[i];
                nowPos = i;
            }
        }
        nowMax = heights.back(); nowPos = n-1;
        for(int i = n-1; i >= maxnPos2; i--) {
            if(heights[i] > nowMax) {
                area2 += (nowPos - i) * nowMax;
                nowMax = heights[i];
                nowPos = i;
            }
        }
        ans = area1 + area2;
        if(maxnPos1 == maxnPos2) {
            ans += maxn;
        }else {
            ans += (maxnPos2 - maxnPos1 + 1) * maxn;
        }
        ans -= sum;
        cout << ans << endl;
    }
    return 0;
}
