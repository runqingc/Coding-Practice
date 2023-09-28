#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool foundAncestor = false;

TreeNode* ancestor = nullptr;
bool post(TreeNode* root, TreeNode* p, TreeNode* q, bool found){
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


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    post(root, p, q, false);
    return ancestor;
}


int main() {
    auto t0 = new TreeNode(0);
    auto t1 = new TreeNode(1);
    auto t2 = new TreeNode(2);
    auto t3 = new TreeNode(3);
    auto t4 = new TreeNode(4);
    auto t5 = new TreeNode(5);
    auto t6 = new TreeNode(6);
    auto t7 = new TreeNode(7);
    auto t8 = new TreeNode(8);
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
