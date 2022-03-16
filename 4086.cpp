#include<bits/stdc++.h>
using namespace std;
struct DNA{
    DNA(string str, int id):dna(str), dnaOrg(str), id(id) {
        rev = mergeSort(0, dna.length());
    }
    int mergeSort(int l, int r) {
        if(r - l <= 1) {
            return 0;
        }
        int mid = (l+r) >> 1;
        int revl = mergeSort(l, mid);
        int revr = mergeSort(mid, r);
        string temp = dna;
        int revThis = 0;
        int p1 = l, p2 = mid, p = l;
        while(p1 < mid && p2 < r) {
            if(dna[p1] <= dna[p2]) {
                temp[p] = dna[p1];
                p1++;
            }else {
                temp[p] = dna[p2];
                revThis += mid - p1;
                p2++;
            }
            p++;
        }
        while(p < r) {
            if(p1 < mid) {
                temp[p] = dna[p1];
                p1++;
            }else {
                temp[p] = dna[p2];
                p2++;
            }
            p++;
        }
        for(int i = l; i < r; i++) {
            dna[i] = temp[i];
        }
        return revl + revr + revThis;
    }
    bool operator<(const DNA& other) const {
        if(rev != other.rev) {
            return rev < other.rev;
        }
        return id < other.id;
    }
    string dna;
    string dnaOrg;
    int rev;
    int id;
};
int main() {
    int n, m;
    cin >> n >> m;
    string str;
    vector<DNA> dnav;
    for(int i = 0; i < m; i++) {
        cin >> str;
        dnav.push_back(DNA(str, i));
        // cout << dnav.back().rev << endl;
    }
    sort(dnav.begin(), dnav.end());
    for(auto dna:dnav) {
        cout << dna.dnaOrg << endl;
    }
    return 0;
}
