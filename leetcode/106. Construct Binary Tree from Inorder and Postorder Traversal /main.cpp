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

treeNode* build(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2){
    if(l1>r1 || l2>r2) return nullptr;
    auto root = new treeNode(postorder[r2]);
    int i = l1;
    int left_size = 0;
    // partition inorder, find left subtree
    if(inorder[l1]!=postorder[r2]){
        for( ; i+1<=r1 && inorder[i+1]!=postorder[r2]; ++i);
        root->left = build(inorder, postorder, l1, i, l2, l2+i-l1);
        left_size = i-l1+1;
        i+=2;
    }else{
        ++i;
    }
    // find right subtree

    if(i<=r1){
        root->right = build(inorder, postorder, i, r1, l2+left_size, r2-1);
    }
    return root;
}


treeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return build(inorder, postorder, 0, (int)inorder.size()-1, 0, (int)postorder.size()-1);
}


int main() {
    vector<int> in{3,15,20,7};
    vector<int>post{15,7,20,3};
    treeNode* root = buildTree(in, post);

    return 0;
}
