#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node(int val):val(val), left(nullptr), right(nullptr) {}
    int val;
    Node* left;
    Node* right;
};
typedef Node* nptr;
nptr root = nullptr;
void insert(nptr now, int val) {
    if(val == now->val) {
        return;
    }
    if(val < now->val) {
        if(now->left) {
            insert(now->left, val);
        }else {
            now->left = new Node(val);
        }
    }else {
        if(now->right) {
            insert(now->right, val);
        }else {
            now->right = new Node(val);
        }
    }
}
void preorder(nptr now) {
    if(!now) {
        return;
    }
    cout << (now->val) << " ";
    preorder(now->left);
    preorder(now->right);
}
int main() {
    int num;
    vector<int> nums;
    while(cin >> num) {
        nums.push_back(num);
    }
    root = new Node(nums.front());
    for(int i = 1; i < nums.size(); i++) {
        insert(root, nums[i]);
    }
    preorder(root);
    return 0;
}
