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

void post(treeNode* root){
    if(root){
        post(root->right);
        int tmp = root->val;
        root->val += sum;
        sum += tmp;
        post(root->left);
    }
}

treeNode* convertBST(treeNode* root) {
    post(root);
    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
