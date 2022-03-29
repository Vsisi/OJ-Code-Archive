#include<bits/stdc++.h>
using namespace std;
const int N = 10;
bool used[N];
vector<int> nowp;
void permutation(int n, int cnt) {
    if(cnt == n) {
        for(int i = 0; i < n; i++) {
            if(i < n-1) {
                cout << nowp[i] << " ";
            }else {
                cout << nowp[i];
            }
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            used[i] = true;
            nowp.push_back(i);
            permutation(n, cnt+1);
            nowp.pop_back();
            used[i] = false;
        }
    }
}
int main() {
    int n;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        memset(used, false, sizeof(used));
        permutation(n, 0);
    }
    return 0;
}
