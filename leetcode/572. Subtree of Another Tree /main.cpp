#include <iostream>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// for every node, check if this is same tree as the subTree
class Solution {
public:

    bool isSame = true;
    bool isSubTree = false;

    void isSameTree(TreeNode* p, TreeNode* q){
        if(isSame){
            if(p && !q || !p && q){
                isSame = false;
            }else if(p && q){
                if(p->val !=q->val){
                    isSame = false;
                }else{
                    isSameTree(p->left, q->left);
                    isSameTree(p->right, q->right);
                }
            }
        }
    }

    bool checkIsSameTree(TreeNode* p, TreeNode* q){
        isSame = true;
        isSameTree(p, q);
        return isSame;
    }

    void preOrder(TreeNode* p, TreeNode* subRoot){
        if(p){
            if(checkIsSameTree(p, subRoot)){
                isSubTree = true;
            }else{
                if(p->left){
                    preOrder(p->left, subRoot);
                }
                if(p->right){
                    preOrder(p->right, subRoot);
                }
            }
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        preOrder(root, subRoot);
        return isSubTree;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
