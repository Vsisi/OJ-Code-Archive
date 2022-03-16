#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node() {
        for(int i = 0; i < 10; i++) {
            sons[i] = nullptr;
        }
        endHere = false;
    }
    bool endHere;
    Node* sons[10];
};
typedef Node* nptr;
bool construct(nptr root, const string& number) {
    nptr now = root;
    bool returnTrue = true;
    for(auto digit:number) {
        if(now->endHere == true) {
            returnTrue = false;
        }
        if(now->sons[digit - '0'] == nullptr) {
            now->sons[digit - '0'] = new Node();
        }
        now = now->sons[digit - '0'];
    }
    if(!now->endHere) {
        now->endHere = true;
    }else {
        returnTrue = false;
    }
    for(int i = 0; i < 10; i++) {
        if(now->sons[i]) {
            return false;
        }
    }
    return returnTrue;
}
void delTree(nptr root) {
    root->endHere = false;
    for(int i = 0; i < 10; i++) {
        if(root->sons[i]) {
            delTree(root->sons[i]);
            root->sons[i] = nullptr;
        }
    }
    delete root;
}
int main() {
    int t;
    cin >> t;
    int n;
    string number;
    nptr root;
    while(t--) {
        root = new Node();
        bool flag = true;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> number;
            if(!construct(root, number)) {
                flag = false;
            }
        }
        delTree(root);
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
