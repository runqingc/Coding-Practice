#include <iostream>
#include <algorithm>
using namespace std;

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};

int max_diameter = 0;

void post_order(treeNode* root){

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


int diameterOfBinaryTree(treeNode* root) {
    post_order(root);
    return max_diameter;
}


int main() {
    auto t3 = treeNode(3);
    auto t4 = treeNode(4);
    auto t5 = treeNode(5);
    auto t2 = treeNode(2, &t4, &t5);
    auto t1 = treeNode(1, &t2, &t3);
    cout << diameterOfBinaryTree(&t1);

    return 0;
}
