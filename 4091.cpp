#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5050;
const int MAXK = 8;
int points[MAXN][MAXK];
int tPoint[MAXK];
int n, k;
struct Answer {
    Answer(int* p, double dis):p(p), dis(dis) {}
    bool operator>(const Answer& rhs) const {
        return this->dis > rhs.dis;
    }
    bool operator<(const Answer& rhs) const {
        return this->dis < rhs.dis;
    }
    int* p;
    double dis;
};
priority_queue<Answer> pq;
Answer calcDis(int* p1, int* p2) {
    double temp = 0;
    for(int i = 0; i < k; i++) {
        temp += (p1[i] - p2[i]) * (p1[i] - p2[i]);
    }
    return Answer(p2, temp);
}
int main() {
    vector<Answer> res; res.clear();
    while(cin >> n >> k) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                scanf("%d", &points[i][j]);
            }
        }
        int t;
        scanf("%d", &t);
        while(t--) {
            for(int i = 0; i < k; i++) {
                scanf("%d", &tPoint[i]);
            }
            int m;
            cin >> m;
            for(int i = 0; i < n; i++) {
                pq.push(calcDis(tPoint, points[i]));
                if(pq.size() > m) {
                    pq.pop();
                }
            }
            while(!pq.empty()) {
                res.push_back(pq.top());
                pq.pop();
            }
            printf("the closest %d points are:\n", m);
            for(int i = m-1; i >= 0; i--) {
                for(int j = 0; j < k; j++) {
                    printf("%d ", res[i].p[j]);
                }
                printf("\n");
            }
            res.clear();
        }
    }
    return 0;
}
