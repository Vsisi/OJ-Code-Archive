#include<bits/stdc++.h>
using namespace std;
int findIdx(const vector<string>& stations, const string& key) {
    for(int i = 0; i < stations.size(); i++) {
        if(key == stations[i]) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n, m;
    cin >> n;
    string station;
    vector<string> stations;
    for(int i = 0; i < n; i++) {
        cin >> station;
        stations.push_back(station);
    }
    cin >> m;
    string ss, es;
    int si, ei;
    for(int i = 0; i < m; i++) {
        cin >> ss >> es;
        si = findIdx(stations, ss); ei = findIdx(stations, es);
        if(si <= ei) {
            for(int j = si; j < ei; j++) {
                cout << stations[j] << " ";
            }
        }else {
            for(int j = si; j > ei; j--) {
                cout << stations[j] << " ";
            }
        }
        cout << stations[ei] << endl;
    }
    return 0;
}
