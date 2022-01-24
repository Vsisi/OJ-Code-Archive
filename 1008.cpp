#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

map<int, vector<string>> mem;

int merge_sort(string& dna, int l, int r);
void merge(string&, int, int, int&);

int main() {
    int n, m;
    cin >> n >> m;
    string dna, tempDNA;
    while(m--) {
        cin >> dna;
        tempDNA = dna;
        mem[merge_sort(tempDNA, 0, n-1)].push_back(dna);
    }
    for(map<int, vector<string>>::iterator it = mem.begin(); it != mem.end(); it++) {
        for(auto res:it->second) {
            cout << res << endl;
        }
    }
}

int merge_sort(string& dna, int l, int r) {
    int totSum = 0;
    if(l >= r) {
        return 0;
    }else if(l + 1 == r) {
        if(dna[l] > dna[r]) {
            swap(dna[l], dna[r]);
            return 1;
        }
        return 0;
    }
    
    totSum += merge_sort(dna, l, (l+r)/2);
    totSum += merge_sort(dna, (l+r)/2 + 1, r);
    merge(dna, l, r, totSum);
    return totSum;
}
void merge(string& str, int l, int r, int& sum) {
    string temp = "";
    int mid = (l + r) >> 1;
    int p1 = l, p2 = mid+1;
    while(p1 <= mid && p2 <= r) {
        if(str[p1] <= str[p2]) {
            temp += str[p1++];
        }else {
            temp += str[p2++];
            sum += mid - p1 + 1;
        }
    }
    for(int i = p1; i <= mid; i++) {
        temp += str[i];
    }
    for(int i = p2; i <= r; i++) {
        temp += str[i];
    }
    for(int i = 0; i <= r-l; i++) {
        str[i+l] = temp[i];
    }
}
