#include<bits/stdc++.h>
using namespace std;
struct Point {
    Point(int x, int y):x(x), y(y) {

    }
    bool operator<(const Point& rhs) {
        return x < rhs.x;
    }
    int x, y;
};
vector<Point> points;
vector<Point> solve(int l, int r) {
    vector<Point> res;
    res.clear();
    if(l == r) {
        res.push_back(points[l]);
        return res;
    }
    vector<Point> resL, resR;
    resL = solve(l, (r+l) >> 1);
    resR = solve(((r+l)>>1)+1, r);
    int maxYR = 0;
    for(auto point:resR) {
        maxYR = max(maxYR, point.y);
    }
    for(auto point:resL) {
        if(point.y <= maxYR) {
            continue;
        }
        res.push_back(point);
    }
    for(auto point:resR) {
        res.push_back(point);
    }
    return res;
}
int main() {
    int n;
    int tempX, tempY;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tempX >> tempY;
        points.push_back(Point(tempX, tempY));
    }
    sort(points.begin(), points.end());
    vector<Point> res;
    res = solve(0, n-1);
    for(int i = 0; i < res.size()-1; i++) {
        printf("(%d,%d),", res[i].x, res[i].y);
    }
    printf("(%d,%d)", res.back().x, res.back().y);
    return 0;
}
