#include <iostream>
using namespace std;

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};


bool foundAncestor = false;

treeNode* ancestor = nullptr;
bool post(treeNode* root, treeNode* p, treeNode* q, bool found){
    bool l = false, r = false, m = false;
    if(root && !foundAncestor){
        if(root->left){
            l = post(root->left, p, q, found);
        }
        if(root->right){
            r = post(root->right, p, q, found);
        }
        m = (root==p) || (root==q);
        if(!foundAncestor){
            if((l && r) || (l && m) || (r && m)){
                ancestor = root;
            }
        }
    }
    return found || l || r || m;
}


treeNode* lowestCommonAncestor(treeNode* root, treeNode* p, treeNode* q) {
    post(root, p, q, false);
    return ancestor;
}


int main() {
    auto t0 = new treeNode(0);
    auto t1 = new treeNode(1);
    auto t2 = new treeNode(2);
    auto t3 = new treeNode(3);
    auto t4 = new treeNode(4);
    auto t5 = new treeNode(5);
    auto t6 = new treeNode(6);
    auto t7 = new treeNode(7);
    auto t8 = new treeNode(8);
    t3->left = t5;
    t3->right = t1;
    t5->left = t6;
    t5->right = t2;
    t1->left = t0;
    t1->right = t8;
    t2->left = t7;
    t2->right = t4;

    cout << lowestCommonAncestor(t3, t5,t4)->val;
    return 0;
}
