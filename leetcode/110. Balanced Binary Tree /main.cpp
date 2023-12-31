#include <iostream>
#include <cmath>
using namespace std;

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};

//void height(TreeNode* root, int depth, int& maxDepth){
//    if(!root) return;
//    // root not null, cur depth: depth+1
//    if(depth+1>maxDepth){
//        maxDepth = depth+1;
//    }
//    height(root)
//
//
//}

bool flag = true;

int post(treeNode* root){
    if(!flag) return -1;
    if(!root) return 0;
    int l=0, r=0;
    if(root->left){
        l = post(root->left)+1;
    }
    if(root->right){
        r = post(root->right)+1;
    }
    if(abs(l-r)>1) flag = false;
    return max(l, r);
}


bool isBalanced(treeNode* root) {
    if(!root) return true;
    post(root);
    return flag;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
