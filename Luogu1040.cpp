#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll score[40];
struct State{
    State():val(-1), rt(-100) {}
    int val;
    int rt;
};
State mem[40][40];
ll calc(int l, int r, int& root) {
    if(l == r) {
        mem[l][r].val = score[l];
        mem[l][r].rt = l;
        root = l;
        return score[l];
    }
    if(l > r) {
        return 1;
    }
    ll res = 0;
    ll tmp;
    int rootL = -1, rootR = -1;
    root = -1;
    int lChild, rChild;
    int leftVal, rightVal;
    for(int i = l; i <= r; i++) {
        if(mem[l][i-1].val == -1) {
            mem[l][i-1].val = calc(l, i-1, rootL);
            mem[l][i-1].rt = rootL;
        }
        if(mem[i+1][r].val == -1) {
            mem[i+1][r].val = calc(i+1, r, rootR);
            mem[i+1][r].rt = rootR;
        }
        tmp = mem[l][i-1].val * mem[i+1][r].val + score[i];
        if(res < tmp) {
            res = tmp;
            root = i;
        }
    }
    mem[l][r].val = res;
    mem[l][r].rt = root;
    return res;
}
void preorder(int rt, int l, int r) {
    if(l > r) {
        return;
    }
    cout << rt << " ";
    preorder(mem[l][rt-1].rt, l, rt-1);
    preorder(mem[rt+1][r].rt, rt+1, r);
}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> score[i];
    }
    ll res = 0;
    ll tmp;
    int rootL, rootR, root, lChild, rChild;
    for(int i = 1; i <= n; i++) {
        if(mem[1][i-1].val == -1) {
            mem[1][i-1].val = calc(1, i-1, rootL);
            mem[1][i-1].rt = rootL;
        }
        if(mem[i+1][n].val == -1) {
            mem[i+1][n].val = calc(i+1, n, rootR);
            mem[i+1][n].rt = rootR;
        }
        tmp = mem[1][i-1].val * mem[i+1][n].val + score[i];
        if(res < tmp) {
            res = tmp;
            root = i;
        }
    }
    mem[1][n].val = res;
    mem[1][n].rt = root;
    cout << res << endl;
    preorder(root, 1, n);
    return 0;
}
