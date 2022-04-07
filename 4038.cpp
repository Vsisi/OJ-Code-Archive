#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
struct Passenger{
    Passenger(int t, int src, int dst):t(t), src(src), dst(dst) {}
    int t, src, dst;
};
int n, m, k;
int t, src, dst;
vector<Passenger> sites[MAXN];
int getoffSites[MAXN] = {0};
int getinSites[MAXN] = {0};
int maxTSites[MAXN] = {0};
int arrTime[MAXN] = {0};
int leaveTime[MAXN] = {0};
int d[MAXN];
int main() {
    cin >> n >> m >> k;
    for(int i = 1; i < n; i++) {
        cin >> d[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> t >> src >> dst;
        sites[dst].push_back(Passenger(t, src, dst));
        getinSites[src]++;
        getoffSites[dst]++;
        maxTSites[src] = max(maxTSites[src], t); 
    }
    int res = 0;
    
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            arrTime[i] = 1;
            leaveTime[i] = maxTSites[1];
        }else {
            arrTime[i] = leaveTime[i-1] + d[i-1];
            leaveTime[i] = max(arrTime[i], maxTSites[i]);
        }
        for(auto passenger:sites[i]) {
            res += arrTime[i] - passenger.t;
        }
    }
    while(k > 0) {
        int maxReduce = 0;
        int sitePos;
        int reduce;
        for(int i = 1; i < n; i++) {
            if(d[i] > 0) {
                reduce = getoffSites[i+1];
                for(int j = i+2; j <= n; j++) {
                    if(arrTime[j-1] > maxTSites[j-1]) { //passengers wait bus
                        reduce += getoffSites[j];
                    }else {
                        break;
                    }
                }
                if(maxReduce < reduce) {
                    maxReduce = reduce;
                    sitePos = i;
                }
            }
        }
        res -= maxReduce;
        d[sitePos]--;
        for(int i = sitePos + 1; i <= n; i++) {
            if(arrTime[i] > maxTSites[i]) {
                arrTime[i]--;
            }else {
                break;
            }
        }

        k--;
    }
    cout << res << endl;
    return 0;
}
