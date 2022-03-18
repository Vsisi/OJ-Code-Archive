#include<bits/stdc++.h>
using namespace std;
int main() {
    list<int> q, s;
    int m;
    cin >> m;
    int n;
    string opr;
    int num;
    bool error;
    while(m--) {
        cin >> n;
        q.clear(); s.clear();
        error = false;
        for(int i = 0; i < n; i++) {
            cin >> opr;
            if(opr == "push") {
                cin >> num;
                if(!error) {
                    q.push_back(num);
                    s.push_back(num);
                }
            }else {
                if(error) {
                    continue;
                }
                if(q.size() > 0) {
                    q.pop_front();
                    s.pop_back();
                }else {
                    error = true;
                }
            }
        }
        if(error) {
            cout << "error" << endl;
            cout << "error" << endl;
        }else {
            for(auto i:q) {
                cout << i << " ";
            }
            cout << endl;
            for(auto i:s) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
