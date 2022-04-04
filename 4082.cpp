#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node(char val):val(val), brother(nullptr), firstSon(nullptr)  {}
    char val;
    Node* brother;
    Node* firstSon;
};
typedef Node* nptr;
nptr root = nullptr;
void constructTree(nptr now, int& idx, const vector<string>& nodeStrs) {
    // cout <<"1    "<< now->val << " " << nodeStrs[idx] << endl;
    if(nodeStrs[idx][0] == '$') {
        idx++;
    }else {
        if(nodeStrs[idx][1] == '0') {
            now->firstSon = new Node(nodeStrs[idx++][0]);
            constructTree(now->firstSon, idx, nodeStrs);
        }else {
            now->firstSon = new Node(nodeStrs[idx++][0]);
        }
    }//left tree finished   
    if(idx >= nodeStrs.size()) {
        return;
    }
    // cout <<"2    "<<  now->val << " " <<nodeStrs[idx] <<  endl;
    if(nodeStrs[idx][0] == '$') {
        idx++;
        return; //no brother
    }else {
        if(nodeStrs[idx][1] == '0') {
            now->brother = new Node(nodeStrs[idx++][0]);
            constructTree(now->brother, idx, nodeStrs);
        }else {
            now->brother = new Node(nodeStrs[idx++][0]);
            return;
        }
    }
}
void mirror(nptr now, nptr father) {
    if(!now) {
        return;
    }
    nptr head = now;
    nptr tail = now;
    for(nptr nBrother = head->brother; nBrother != nullptr;) {
        nptr nnBrother = nBrother->brother;
        tail->brother = nnBrother;
        nBrother->brother = head;
        head = nBrother;
        nBrother = nnBrother;
    }
    if(father) {
        father->firstSon = head;
    }else {
        root = head;
    }
    for(nptr fBrother = head; fBrother != nullptr; fBrother = fBrother->brother) {
        mirror(fBrother->firstSon, fBrother);
    }
}
void traversal() {
    queue<nptr> q;
    q.push(root);
    nptr now;
    while(!q.empty()) {
        now = q.front(); q.pop();
        for(nptr b = now; b != nullptr; b = b->brother) {
            cout << b->val << " ";
            if(b->firstSon) {
                q.push(b->firstSon);
            }
        }
    }
}
int main() {
    int n;
    string nodeStr, tempStr;
    vector<string> nodeStrs;
    cin >> n;
    if(n == 0) {
        return 0;
    }
    for(int i = 0; i < n; i++) {
        cin >> tempStr;
        nodeStrs.push_back(tempStr);
    }
    int idx = 1;
    root = new Node(nodeStrs[0][0]);
    constructTree(root, idx, nodeStrs);
    // traversal();cout << endl;
    mirror(root, nullptr);
    traversal();
    return 0;
}
