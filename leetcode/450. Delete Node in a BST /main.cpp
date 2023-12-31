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

treeNode* deleteNode(treeNode* root, int x){
    if(!root) return nullptr;
    else if(x>root->val){
        root->right = deleteNode(root->right, x);
    }
    else if(x<root->val){
        root->left = deleteNode(root->left, x);
    }
    else if(!root->left){
        treeNode* tmp = root->right;
        delete root;
        return tmp;
    }
    else if(!root->right){
        treeNode* tmp = root->left;
        delete root;
        return tmp;
    }else{
        // find max from left
        treeNode* tmp = root->left;
        while(tmp->right){
            tmp = tmp->right;
        }
        int tmpVal = tmp->val;
        root->val = tmpVal;
        root->left = deleteNode(root->left, tmpVal);
    }

    return root;
}



int main() {
    auto t2 = new treeNode(2);
    auto t4 = new treeNode(4);
    auto t7 = new treeNode(7);
    auto t3 = new treeNode(3, t2, t4);
    auto t6 = new treeNode(6, nullptr, t7);
    auto t5 = new treeNode(5, t3, t6);
    t5 = deleteNode(t5, 3);

    return 0;
}
