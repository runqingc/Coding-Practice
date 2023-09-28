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

TreeNode* deleteNode(TreeNode* root, int x){
    if(!root) return nullptr;
    else if(x>root->val){
        root->right = deleteNode(root->right, x);
    }
    else if(x<root->val){
        root->left = deleteNode(root->left, x);
    }
    else if(!root->left){
        TreeNode* tmp = root->right;
        delete root;
        return tmp;
    }
    else if(!root->right){
        TreeNode* tmp = root->left;
        delete root;
        return tmp;
    }else{
        // find max from left
        TreeNode* tmp = root->left;
        while(tmp->right){
            tmp = tmp->right;
        }
        int tmpVal = tmp->val;
        root->val = tmpVal;
        root->left = deleteNode(root->left, tmpVal);
    }

    return root;
}



int main() {
    auto t2 = new TreeNode(2);
    auto t4 = new TreeNode(4);
    auto t7 = new TreeNode(7);
    auto t3 = new TreeNode(3, t2, t4);
    auto t6 = new TreeNode(6, nullptr, t7);
    auto t5 = new TreeNode(5, t3, t6);
    t5 = deleteNode(t5, 3);

    return 0;
}
