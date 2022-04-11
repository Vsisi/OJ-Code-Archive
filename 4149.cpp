#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Course{
    Course(string courseName, int ddl, int needTime):courseName(courseName), ddl(ddl), needTime(needTime) {}
    bool operator<(const Course& rhs) const {
        return this->courseName < rhs.courseName;
    }
    string courseName;
    int needTime, ddl;
};
struct State{
    int minVal = INF;
    int lastSet = -1;
    int last = -1;
    int lastDay = 0;
};
State dp[1<<17];
typedef pair<int, int> pii;
pii calcInc(int lastDay, Course course) {
    if(lastDay + course.needTime < course.ddl) {
        return pii(0, lastDay + course.needTime);
    }else {
        return pii(lastDay + course.needTime - course.ddl, lastDay + course.needTime);
    }
}
vector<string> getPath(int dpidx, const vector<Course>& course) {
    vector<string> res;
    int now = dpidx;
    while(dp[now].last != -1) {
        res.push_back(course[dp[now].last].courseName);
        now = dp[now].lastSet;
    }
    reverse(res.begin(), res.end());
    return res;
}
bool operator<(const vector<string>& a, const vector<string>& b) {
    for (int i = 0, j = 0; i < a.size() && j < b.size(); i++, j++) {
        if (a[i] < b[j])
            return true;
        else if (a[i] > b[j])
            return false;
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    int n;
    string courseName;
    int ddl, needTime;
    vector<Course> course;
    bitset<15> prevSet;
    while(t--) {
        course.clear();
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> courseName >> ddl >> needTime;
            course.push_back(Course(courseName, ddl, needTime));
        }
        dp[0].last = -1;
        dp[0].lastSet = -1;
        dp[0].minVal = 0;
        dp[0].lastDay = 0;
        for(int i = 1; i < (1<<n); i++) {
            bitset<15> curSet(i);
            dp[i].last = -1;
            dp[i].lastDay = 0;
            dp[i].minVal = INF; //init dp[i]
            for(int j = 0; j < n; j++) {
                if(curSet.test(j)) {
                    prevSet = curSet; prevSet.reset(j);
                    pii delta = calcInc(dp[prevSet.to_ulong()].lastDay, course[j]);
                    int curSeti = curSet.to_ulong(), prevSeti = prevSet.to_ulong();
                    if(dp[curSeti].minVal >= dp[prevSeti].minVal + delta.first) {
                        if(dp[curSeti].last == -1 || dp[curSeti].minVal > dp[prevSeti].minVal + delta.first) {
                            dp[curSeti].lastSet = prevSeti;
                            dp[curSeti].last = j;
                            dp[curSeti].lastDay = delta.second;
                            dp[curSeti].minVal = dp[prevSeti].minVal + delta.first;
                        }else { //equals and not first
                            vector<string> pathOld, pathNew;
                            pathOld = getPath(curSeti, course);
                            pathNew = getPath(prevSeti, course);
                            if(pathNew < pathOld) { //keep lexicographical
                                dp[curSeti].lastSet = prevSeti;
                                dp[curSeti].last = j;
                                dp[curSeti].lastDay = delta.second;
                                dp[curSeti].minVal = dp[prevSeti].minVal + delta.first;
                            }
                        }
                    }
                }
            }
        }
        int now = (1<<n)-1;
        cout << dp[now].minVal << endl;
        vector<string> rres = getPath(now, course);
        for(auto name:rres) {
            cout << name << endl;
        }
    }
    return 0;
}
