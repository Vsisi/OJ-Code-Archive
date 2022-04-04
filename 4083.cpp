#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
map<string, int> name2id;
map<int, string> id2name;
int p;
int edgeWeight[50][50];
bool visited[50];
int dis[50];
int from[50];
void dijkstra(int src, int dst) {
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 50; i++) {dis[i] = INF; from[i] = 0;}
    dis[src] = 0; from[src] = -1;
    
    int minDis, tgtU;
    for(int i = 0; i < p; i++) {
        minDis = INF;
        for(int u = 0; u < p; u++) {
            if(!visited[u] && dis[u] < minDis) {
                tgtU = u;
                minDis = dis[u];
            }
        }
        visited[tgtU] = true;
        for(int v = 0; v < p; v++) {
            if(!visited[v] && dis[tgtU] + edgeWeight[tgtU][v] < dis[v]) {
                from[v] = tgtU;
                dis[v] = dis[tgtU] + edgeWeight[tgtU][v];
            }
        }
    }
    int now = dst;
    vector<int> path;
    while(now != -1) {
        path.push_back(now);
        now = from[now];
    }
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size()-1; i++) {
        printf("%s->(%d)->", id2name[path[i]].c_str(), edgeWeight[path[i]][path[i+1]]);
    }
    cout << id2name[path.back()] << endl;
}
int main() {
    int id = 0;
    string name;
    cin >> p;
    for(int i = 0; i < p; i++) {
        cin >> name;
        name2id[name] = id;
        id2name[id] = name;
        id++;
    }
    for(int i = 0; i < id; i++) {
        for(int j = 0; j < id; j++) {
            edgeWeight[i][j] = INF;
        }
    }
    int q;
    cin >> q;
    string name1, name2;
    int tmpDis;
    for(int i = 0; i < q; i++) {
        cin >> name1 >> name2 >> tmpDis;
        edgeWeight[name2id[name1]][name2id[name2]] = min(tmpDis, edgeWeight[name2id[name1]][name2id[name2]]);
        edgeWeight[name2id[name2]][name2id[name1]] = min(tmpDis, edgeWeight[name2id[name2]][name2id[name1]]);
    }
    int r;
    cin >> r;
    for(int i = 0; i < r; i++) {
        cin >> name1 >> name2;
        dijkstra(name2id[name1], name2id[name2]);
    }
    return 0;
}
