#include<bits/stdc++.h>
using namespace std;
struct State{
    State(string str):str(str) {
        step = 1;
        visited.clear();
    }
    string str;
    int step;
    map<string, bool> visited;
};
int main() {
    string src, dst;
    cin >> src >> dst;
    int len = src.length();
    string word;
    map<string, bool> inDict;
    while(cin >> word) {
        inDict[word] = true;
    }
    queue<State> q;
    q.push(State(src));
    while(!q.empty()) {
        State now = q.front();
        q.pop();
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if(now.str[i] != dst[i]) {
                cnt++;
            }
            if(cnt > 1) {
                break;
            }
        }
        if(cnt == 1) {
            cout << now.step + cnt << endl;
            return 0;
        }
        for(auto p:inDict) {
            if(now.visited[p.first]) {
                continue;
            }
            cnt = 0;
            for(int i = 0; i < len; i++) {
                if(now.str[i] != p.first[i]) {
                    cnt++;
                }
                if(cnt > 1) {
                    break;
                }
            }
            if(cnt == 1) {
                string temp = now.str;
                now.step++;
                now.str = p.first;
                now.visited[p.first] = true;
                q.push(now);
                now.step--;
                now.visited[p.first] = false;
                now.str = temp;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}
