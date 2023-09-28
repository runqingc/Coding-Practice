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

int last = -1;
int minDifference = INT32_MAX;

void inOrder(TreeNode* root){
    if(root){
        if(root->left){
            inOrder(root->left);
        }
        if(last!=-1){
            int currentDifference = root->val-last;
            if(currentDifference<minDifference){
                minDifference = currentDifference;
            }
        }
        last = root->val;
        if(root->right){
            inOrder(root->right);
        }
    }
}

int getMinimumDifference(TreeNode* root) {
    inOrder(root);
    return minDifference;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
