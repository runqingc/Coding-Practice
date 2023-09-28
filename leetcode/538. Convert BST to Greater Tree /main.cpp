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

void post(TreeNode* root){
    if(root){
        post(root->right);
        int tmp = root->val;
        root->val += sum;
        sum += tmp;
        post(root->left);
    }
}

TreeNode* convertBST(TreeNode* root) {
    post(root);
    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
