#include <iostream>

struct treeNode {
     int val;
     treeNode *left;
     treeNode *right;
     treeNode() : val(0), left(nullptr), right(nullptr) {}
     treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};


// for every node, check if this is same tree as the subTree
class Solution {
public:

    bool isSame = true;
    bool isSubTree = false;

    void isSameTree(treeNode* p, treeNode* q){
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

    bool checkIsSameTree(treeNode* p, treeNode* q){
        isSame = true;
        isSameTree(p, q);
        return isSame;
    }

    void preOrder(treeNode* p, treeNode* subRoot){
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

    bool isSubtree(treeNode* root, treeNode* subRoot) {
        preOrder(root, subRoot);
        return isSubTree;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
