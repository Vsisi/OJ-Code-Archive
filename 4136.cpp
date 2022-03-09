#include<bits/stdc++.h>
using namespace std;
class Rectangle{
public:
    Rectangle(long long l, long long t, long long w, long long h) {
        lt = pair<long long, long long>(l, t);
        rb = pair<long long, long long>(l+w, t-h);
        area = w * h;
        this->h = h;
    }
    pair<long long, long long> split(long long axis) { //first: left, second: right
        if(rb.first <= axis) {
            return pair<long long, long long>(area, 0);
        }else if(axis <= lt.first) {
            return pair<long long, long long>(0, area);
        }else {
            return pair<long long, long long>((axis-lt.first)*h, (rb.first-axis)*h);
        }
    }
    long long dir(long long axis) {
        if(area == 0) {
            return -1;
        }
        if(rb.first <= axis) { //left
            return 1;
        }else if(axis <= lt.first) { //right
            return -1;
        }else { //mid
            return 0;
        }
    }
    pair<long long, long long> lt, rb;
    long long h;
    long long area;
};
vector<Rectangle> rects;
long long comp(long long a, long long b) {
    long long leftAreaA = 0, leftAreaB = 0, rightAreaA = 0, rightAreaB = 0;
    pair<long long, long long> temp;
    for(auto rect:rects) {
        temp = rect.split(a);
        leftAreaA += temp.first;
        rightAreaA += temp.second;
    }
    for(auto rect:rects) {
        temp = rect.split(b);
        leftAreaB += temp.first;
        rightAreaB += temp.second;
    }
    if(leftAreaA < rightAreaA) {
        return b;
    }else if(leftAreaB < rightAreaB) {
        return a;
    }else {
        return (leftAreaA - rightAreaA) < (leftAreaB - rightAreaB) ? a : b;
    }
}
int main() {
    long long r;
    cin >> r;
    long long n;
    cin >> n;
    long long l, t, w, h;
    for(long long i = 0; i < n; i++) {
        cin >> l >> t >> w >> h;
        rects.push_back(Rectangle(l, t, w, h));
    }
    rects.push_back(Rectangle(r, r, 0, 0));
    long long lb = 0, rb = r;
    while(rb-lb > 1) {
        long long mid = (lb+rb) >> 1;
        long long leftArea = 0, rightArea = 0;
        pair<long long, long long> temp;
        for(auto rect:rects) {
            temp = rect.split(mid);
            leftArea += temp.first;
            rightArea += temp.second;
        }
        if(leftArea < rightArea) {
            lb = mid+1;
        }else if(leftArea > rightArea) {
            rb = mid;
        }else {//==
            lb = mid;
            break;
        }
    }
    long long preRes = comp(lb, rb);
    bool intersec = false;
    long long minLarge = r;
    for(auto rect:rects) {
        if(rect.dir(preRes) == 0) {
            intersec = true;
            break;
        }
        if(rect.dir(preRes) == -1) { //rect on the right of axis
            minLarge = min(rect.lt.first, minLarge);
        }
    }
    if(intersec) {
        cout << preRes;
    }else {
        cout << minLarge;
    }
    return 0;
}
