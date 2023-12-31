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

int last = -1;
int minDifference = INT32_MAX;

void inOrder(treeNode* root){
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

int getMinimumDifference(treeNode* root) {
    inOrder(root);
    return minDifference;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
