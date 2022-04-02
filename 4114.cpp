#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld eps = 1e-8;
const string yes = "Yes!";
const string no = "No!";
struct Segment;
ostream& operator<<(ostream& out, const Segment& seg);
struct Segment{
    Segment(ld x1, ld y1, ld x2, ld y2):x1(x1), y1(y1), x2(x2), y2(y2) {
        if(fabs(x2 - x1) < eps) {
            infK = true;
        }else {
            k = (y2-y1) / (x2-x1);
            b = (y1*x2 - x1*y2) / (x2-x1);
            infK = false;
        }
    }
    bool hasIntersection(const Segment& other) {
        if(this->infK) {
            ld minX = min(other.x1, other.x2);
            ld maxX = max(other.x1, other.x2);
            if(fabs(minX - this->x1) < eps || fabs(maxX - this->x1) < eps) {
                return true;
            }else if(minX < this->x1 && this->x1 < maxX) {
                return true;
            }
            return false;
        }
        if(!other.infK) {
            if(fabs(this->k - other.k) < eps) {
                return fabs(this->b - other.b) < eps;
            }
        }
        ld t;
        if(!other.infK) {
            ld intersectX = (other.b - this->b) / (this->k - other.k);
            t = (intersectX - other.x1) / (other.x2 - other.x1);
        }else {
            t = (this->k * other.x1 + this->b - other.y1) / (other.y2 - other.y1);
        }
        if(fabs(t - 0) < eps || fabs(t - 1) < eps) {
            return true;
        }else if(t > 0 && t < 1) {
            return true;
        } 
        return false;
    }
    ld k, b;
    ld x1, y1, x2, y2;
    bool infK;
};

int main() {
    int t;
    cin >> t;
    int n;
    ld myx1, myx2, myy1, myy2;
    vector<Segment> segs;
    while(t--) {
        segs.clear();

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> myx1 >> myy1 >> myx2 >> myy2;
            segs.push_back(Segment(myx1, myy1, myx2, myy2));
        }
        bool hasSolution = false;
        for(int i = 0; i < n && !hasSolution; i++) {
            hasSolution = true;
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    continue;
                }
                if(!segs[i].hasIntersection(segs[j])) {
                    hasSolution = false;
                    break;
                }
            }
        }
        if(hasSolution) {
            cout << yes << endl;
        }else {
            cout << no << endl;
        }
    }
    return 0;
}   
ostream& operator<<(ostream& out, const Segment& seg) {
    out << seg.x1 << " " << seg.y1 << " " << seg.x2 << " " << seg.y2 << " " << seg.infK <<  endl;
    return out;
}
