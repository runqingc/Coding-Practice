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


treeNode* origin;
treeNode* trimBST(treeNode* root, int low, int high) {
    if(root && root->val>high){
        auto tmp = root;
        root = root->left;
        delete tmp;
        if(root) root = trimBST(root, low, high);
    }
    if(root && root->val<low){
        auto tmp = root;
        root = root->right;
        delete tmp;
        if(root) root = trimBST(root, low, high);
    }
    if(root && root->left){
        root->left = trimBST(root->left, low, high);
    }
    if(root && root->right){
        root->right = trimBST(root->right, low, high);
    }
    return root;
}


int main() {


//    auto t1 = new TreeNode(1);
//    auto t2 = new TreeNode(2, t1, nullptr);
//    auto t0 = new TreeNode(0, nullptr, t2);
//    auto t4 = new TreeNode(4);
//    auto t3 = new TreeNode(3, t0, t4);
//    t3 = trimBST(t3,1,3);
    auto t2 = new treeNode(2);
    auto t1 = new treeNode(1, nullptr, t2);
    t1 = trimBST(t1, 2,4);
    return 0;
}
