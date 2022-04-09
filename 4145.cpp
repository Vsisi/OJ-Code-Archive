#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct Course{
    Course(double a, double b):a(a), b(b) {}
    bool operator<(const Course& rhs) const {
        return this->weight > rhs.weight;
    }
    void setWeight(double r) {
        weight = (-r * b + a*100);
    };
    double a, b;
    double weight;
};
int main() {
    int n, k;
    double tmp;
    vector<double> a;
    vector<Course> courses;
    while(cin >> n >> k) {
        if(!n && !k) {
            break;
        }
        a.clear(); courses.clear();
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            courses.push_back(Course(a[i], tmp));
        }
        double lr = 0, rr = 120, midr;
        double sum = 0;
        while((rr-lr) > eps) {
            sum = 0;
            midr = (lr + rr) / 2;
            for(int i = 0; i < n; i++) {
                courses[i].setWeight(midr);
            }
            sort(courses.begin(), courses.end());
            for(int i = 0; i < n-k; i++) {
                sum += courses[i].weight;
            }
            if(sum > 0) {
                lr = midr;
            }else {
                rr = midr;
            }
        }
        cout << int((lr + rr) / 2 + 0.5) << endl;
    }
    return 0;
}
