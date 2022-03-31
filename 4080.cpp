#include<bits/stdc++.h>
using namespace std;
struct HuffmanNode {
    HuffmanNode(int val):val(val), left(nullptr), right(nullptr) {}
    int val;
    HuffmanNode *left;
    HuffmanNode * right;
};
struct HuffmanNodePointer{
    HuffmanNodePointer(HuffmanNode* p):p(p) {}
    HuffmanNodePointer(int val) {
        p = new HuffmanNode(val);
    }
    bool operator<(const HuffmanNodePointer& other) const {
        return (this->p)->val < (other.p)->val;
    }
    bool operator>(const HuffmanNodePointer& other) const {
        return (this->p)->val > (other.p)->val;
    }
    HuffmanNode* p;
};
void calcAns(HuffmanNode* now, int depth, int& ans) {
    if(!(now->left) && !(now->right)) {
        ans += depth * now->val;
        return;
    }
    calcAns(now->left, depth + 1, ans);
    calcAns(now->right, depth + 1, ans);
}
int main() {
    int n;
    cin >> n;
    int tempNum;
    priority_queue<HuffmanNodePointer, vector<HuffmanNodePointer>, greater<HuffmanNodePointer>> pq;
    for(int i = 0; i < n; i++) {
        cin >> tempNum;
        pq.push(HuffmanNodePointer(tempNum));
    } 
    HuffmanNode* newNode;
    while(pq.size() > 1) {
        HuffmanNode* p1 = pq.top().p; pq.pop();
        HuffmanNode* p2 = pq.top().p; pq.pop();
        newNode = new HuffmanNode(p1->val + p2->val);
        newNode->left = p1; newNode->right = p2;
        pq.push(newNode);
    }
    int ans = 0;
    calcAns(pq.top().p, 0, ans);
    cout << ans;
    return 0;
}
