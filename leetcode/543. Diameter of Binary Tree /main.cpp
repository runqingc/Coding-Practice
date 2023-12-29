#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int max_diameter = 0;

void post_order(TreeNode* root){

    if(root){
        if(!root->left && !root->right){
            root->val = 0;
        }else if(root->left && !root->right){
            post_order(root->left);
            root->val = root->left->val+1;
            max_diameter = max(max_diameter, root->val);
        }else if(!root->left && root->right){
            post_order(root->right);
            root->val = root->right->val+1;
            max_diameter = max(max_diameter, root->val);
        }else{
            post_order(root->left);
            post_order(root->right);
            root->val = max(root->left->val, root->right->val)+1;
            max_diameter = max(max_diameter, root->left->val+1+root->right->val+1);
        }
    }
}


int diameterOfBinaryTree(TreeNode* root) {
    post_order(root);
    return max_diameter;
}


int main() {
    auto t3 = TreeNode(3);
    auto t4 = TreeNode(4);
    auto t5 = TreeNode(5);
    auto t2 = TreeNode(2, &t4, &t5);
    auto t1 = TreeNode(1, &t2, &t3);
    cout << diameterOfBinaryTree(&t1);

    return 0;
}
