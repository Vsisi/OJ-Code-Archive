#include<bits/stdc++.h>
using namespace std;
const int N = 100;
const int INF = 0x3fffffff;
void printCase() {
    static int cases = 1;
    printf("Case %d:\n", cases++);
}
struct Edge{
    Edge(int v, int w):v(v), w(w) {}
    int v, w;
};
vector<Edge> edges[N];
map<string, int> getId;
int n;
void printRes(int dis) {
    if(dis <= 6000) {
        cout << 3 << endl;
    }else if(dis <= 12000) {
        cout << 4 << endl;
    }else if(dis <= 22000) {
        cout << 5 << endl;
    }else if(dis <= 32000) {
        cout << 6 << endl;
    }else {
        cout << 6 + ceil((dis - 32000) * 1.0 / 20000) << endl;
    }
    return;
}
int dijkstra(int s, int e) {
    bool visited[N]; memset(visited, false, sizeof(visited));
    int dis[N]; for(int i = 0; i < N; i++) {dis[i] = INF;}
    dis[s] = 0;
    visited[s] = true;
    for(int i = 0; i < n-1; i++) {
        int minn = INF, u;
        for(int j = 1; j <= n; j++) {
            if(visited[j]) {
                for(auto edge:edges[j]) {
                    if(!visited[edge.v] && minn > dis[j] + edge.w) {
                        minn = dis[j] + edge.w;
                        u = edge.v;
                    }
                }
            }
        }
        visited[u] = true;
        dis[u] = minn;
        for(auto edge:edges[u]) {
            if(!visited[edge.v]) {
                dis[edge.v] = min(dis[edge.v], dis[u] + edge.w);
            }
        }
    }
    return dis[e];
}
int main() {
    int cases;
    cin >> cases;
    int l, d, m;
    int tempDis;
    string tempName1, tempName2;
    vector<string> name;
    vector<int> dis;
    int curId;
    while(cases--) {
        getId.clear();
        for(int i = 0; i < 100; i++) {edges[i].clear();}
        curId = 1;
        n = 0;

        cin >> l >> d;
        while(l--) {
            name.clear();
            dis.clear();

            cin >> m;
            m--;
            while(m--) {
                cin >> tempName1 >> tempDis;
                name.push_back(tempName1);
                dis.push_back(tempDis);
                if(getId[tempName1] == 0) {
                    getId[tempName1] = curId++;
                    n++;
                }
            }
            cin >> tempName1; name.push_back(tempName1);
            if(getId[tempName1] == 0) {
                    getId[tempName1] = curId++;
                    n++;
            }
            for(int p = 0; p < name.size() - 1; p++) {
                edges[getId[name[p]]].push_back(Edge(getId[name[p+1]], dis[p]));
                edges[getId[name[p+1]]].push_back(Edge(getId[name[p]], dis[p]));
            }
        }
        printCase();
        while(d--) {
            cin >> tempName1 >> tempName2;
            int ans = dijkstra(getId[tempName1], getId[tempName2]);
            printRes(ans);
        }
    }
    return 0;
}
