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

int last = INT32_MIN;
int numSame = 0;
int maxSame = 0;
vector<int> mode;

void inOrder(TreeNode* root){
    if(root){
        if(root->left){
            inOrder(root->left);
        }
        if(last==root->val){
            ++numSame;
        }else{
            numSame = 1;
        }
        if(numSame>maxSame){
            maxSame = numSame;
            mode.clear();
            mode.push_back(root->val);
        }else if(numSame==maxSame){
            if(mode.back()!=root->val){
                mode.push_back(root->val);
            }
        }

        last = root->val;
        if(root->right){
            inOrder(root->right);
        }
    }

}

vector<int> findMode(TreeNode* root) {
    inOrder(root);
    return mode;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
