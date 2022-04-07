#include<bits/stdc++.h>
using namespace std;
bool visited[30];
int n, t;
int ans = 0;
vector<int> v;
void dfs(int idx, int sum) {
    if(sum == t) {
        ans++;
        return;
    }else if(sum > t) {
        return;
    }
    for(int i = idx+1; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, sum + v[i]);
            visited[i] = false;
        }
    }
}
int main() {
    cin >> n >> t;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    for(int i = 0; i < n; i++) {
        dfs(i, v[i]);
    }
    cout << ans;
    return 0;
}
