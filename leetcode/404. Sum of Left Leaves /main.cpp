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

int sum = 0;
void pre(treeNode* root){
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

int sumOfLeftLeaves(treeNode* root) {
    pre(root);
    return sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
