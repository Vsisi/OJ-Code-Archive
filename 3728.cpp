#include<bits/stdc++.h>
using namespace std;
unordered_map<int, bool> m;
int solve(int a, int n) {
    queue<int> time2;
    queue<int> time3;
    n--;
    time2.push(2 * a + 1);
    time3.push(3 * a + 1);
    int k = n;
    int now;
    for(int i = 0; i < k; i++) {
        if(time2.front() < time3.front()) {
            now = time2.front();
            time2.pop();
        }else if(time2.front() > time3.front()) {
            now = time3.front();
            time3.pop();
        }else { //equals
            now = time2.front();
            time2.pop();time3.pop();
        }
        // cout << now << endl;
        // system("pause");
        time2.push((now<<1) + 1);
        time3.push((now<<1) + now + 1);
    }
    return now;
}
int main() {
    int a, n;
    while(cin >> a >> n) {
        printf("%d\n", solve(a, n));
    }
    return 0;
}
