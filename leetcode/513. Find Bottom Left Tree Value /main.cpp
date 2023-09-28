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

int bl;
int maxHeight = -1;

void pre(TreeNode* root, int d){
    if(root){
        if(d>maxHeight){
            maxHeight = d;
            bl = root->val;
        }
        pre(root->left, d+1);
        pre(root->right, d+1);
    }
}

int findBottomLeftValue(TreeNode* root) {
    pre(root, 0);
    return bl;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
