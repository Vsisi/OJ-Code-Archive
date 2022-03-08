#include<bits/stdc++.h>
using namespace std;
bool avail[1100] = {false};
struct SS{
    SS(int val, vector<int> condition) {
        this->val = val;
        this->condition = condition;
    }
    int val;
    vector<int> condition;
};
int main() {
    int num[10];
    cin >> num[1] >> num[2] >> num[3] >> num[4] >> num[5] >> num[6];
    int weight[10];
    weight[1] = 1; weight[2] = 2; weight[3] = 3; weight[4] = 5; weight[5] = 10; weight[6] = 20;
    int cnt = 0;
    avail[0] = true;
    stack<SS> s;

    vector<int> temp;
    for(int i = 1; i <= 6; i++) { //init
        if(num[i] > 0) {
            temp.clear();
            for(int j = 1; j <= 6; j++) {
                if(i != j) {
                    temp.push_back(num[j]);
                }else{
                    temp.push_back(num[j]-1);
                }
            }
            s.push(SS(weight[i], temp));
        }
    }

    while(!s.empty()) {
        SS top = s.top();
        s.pop();
        if(!avail[top.val]) {
            cnt++;
            avail[top.val] = true;
            for(int i = 0; i < 6; i++) {
                if(top.condition[i] > 0 && !avail[top.val + weight[i+1]]) { //remain weight
                    temp.clear();
                    for(int j = 0; j < 6; j++) {
                        if(i != j) {
                            temp.push_back(top.condition[j]);
                        }else {
                            temp.push_back(top.condition[j]-1);
                        }
                    }
                    s.push(SS(top.val + weight[i+1], temp));
                }
            }
        }
    }
    cout << "Total=" << cnt;
    return 0;
}
