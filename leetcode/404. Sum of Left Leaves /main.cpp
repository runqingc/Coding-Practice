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

int sum = 0;
void pre(TreeNode* root){
    if(root){
        if(root->left){
            if(!root->left->left && !root->left->right){
                sum += root->left->val;
            }else{
                pre(root->left);
            }
        }
        if(root->right){
            pre(root->right);
        }

    }
}

int sumOfLeftLeaves(TreeNode* root) {
    pre(root);
    return sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
