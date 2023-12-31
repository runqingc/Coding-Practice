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

int last = INT32_MIN;
int numSame = 0;
int maxSame = 0;
vector<int> mode;

void inOrder(treeNode* root){
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

vector<int> findMode(treeNode* root) {
    inOrder(root);
    return mode;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
