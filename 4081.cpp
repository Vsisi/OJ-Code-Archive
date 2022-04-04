#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node():father(nullptr) {
        sons.clear();
    }
    Node(Node* father):father(father) {
        sons.clear();
    }
    Node* father;
    vector<Node*> sons;
};
typedef Node* nptr;
struct BNode{
    BNode():left(nullptr), right(nullptr) {}
    BNode* left;
    BNode* right;
};
typedef BNode* bnptr;
void constructBinaryTree(nptr now, bnptr bnow) {
    if(now->sons.size() == 0) {
        return;
    }
    bnow->left = new BNode();
    bnow = bnow->left;
    constructBinaryTree(now->sons[0], bnow);
    for(int i = 1; i < now->sons.size(); i++) {
        bnow->right = new BNode();
        constructBinaryTree(now->sons[i], bnow->right);
        bnow = bnow->right;
    }
}
void traverse(bnptr bnow, int maxHeight, int& maxHeightBinary) {
    if(!bnow) {
        return;
    }
    maxHeightBinary = max(maxHeight, maxHeightBinary);
    traverse(bnow->left, maxHeight + 1, maxHeightBinary);
    traverse(bnow->right, maxHeight + 1, maxHeightBinary);
}
int main() {
    string opStr;
    cin >> opStr;
    int nowHeight = 0;
    int maxHeightTree = 0;
    int maxHeightBinary = 0;
    nptr root = new Node;
    nptr now = root;
    for(auto op:opStr) {
        if(op == 'd') {
            now->sons.push_back(new Node(now));
            now = now->sons.back();
            nowHeight++;
            maxHeightTree = max(nowHeight, maxHeightTree);
        }else { //up
            now = now->father;
            nowHeight--;
        }
    }
    bnptr broot = new BNode;
    constructBinaryTree(root, broot);
    traverse(broot, 0, maxHeightBinary);
    printf("%d => %d", maxHeightTree, maxHeightBinary);
    return 0; 
}
