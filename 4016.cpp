#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Student{
    Student(ll id, ll score, int seq):score(score), id(id), seq(seq) {}
    bool operator<(const Student& rhs) {
        if(this->score != rhs.score) {

            return this->score > rhs.score;
        }
        return this->seq < rhs.seq;
    }
    ll score, id;
    int seq;
};
int main() {
    int n;
    cin >> n;
    ll id, score;
    vector<Student> stds;
    for(int i = 0; i < n; i++) {
        cin >> id >> score;
        stds.push_back(Student(id, score, i));
    }
    sort(stds.begin(), stds.end());
    for(int i = 0; i < n; i++) {
        cout << stds[i].id << endl;
    }
    return 0;
}
