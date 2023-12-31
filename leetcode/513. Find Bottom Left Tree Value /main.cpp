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

int bl;
int maxHeight = -1;

void pre(treeNode* root, int d){
    if(root){
        if(d>maxHeight){
            maxHeight = d;
            bl = root->val;
        }
        pre(root->left, d+1);
        pre(root->right, d+1);
    }
}

int findBottomLeftValue(treeNode* root) {
    pre(root, 0);
    return bl;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
