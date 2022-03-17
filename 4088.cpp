#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    map<int, int> aub;
    int temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        aub[temp]++;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &temp);
        aub[temp]++;
    }
    for(auto pairs:aub) {
        if(pairs.second == 1) {
            printf("%d ", pairs.first);
        }
    }
    return 0;
}
