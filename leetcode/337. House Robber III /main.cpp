#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // pair[0] do not rob; pair[1] rob
    void post(unordered_map<treeNode*, pair<int, int>>& umap, treeNode* root){
        if(root){

            post(umap, root->left);
            post(umap, root->right);

            if(!root->left && !root->right){
                umap[root] = {0, root->val};
            }else if(!root->left){
                // only have right subtree
                umap[root] = {max(umap[root->right].first, umap[root->right].second), umap[root->right].first+root->val};
            }else if(!root->right){
                // only have left subtree
                umap[root] = {max(umap[root->left].first, umap[root->left].second), umap[root->left].first+root->val};
            }else{
                // have both left and right subtree

                umap[root] = {max(umap[root->left].first, umap[root->left].second)+
                              max(umap[root->right].first, umap[root->right].second),
                              umap[root->left].first+umap[root->right].first+root->val};
            }
        }
    }


    int rob(treeNode* root) {
        unordered_map<treeNode*, pair<int, int>> umap;
        post(umap, root);
        return max(umap[root].first, umap[root].second);
    }
};



int main() {

    auto t1 = new treeNode(4);
    auto t2 = new treeNode(1);
    auto t3 = new treeNode(2);
    auto t4 = new treeNode(3);
    auto t5 = new treeNode(3);
    auto t6 = new treeNode(1);
    t1->left = t2;
//    t1->right = t3;
    t2->left = t3;
    t3->left = t4;
//    t3->right =t6;
    Solution s1;
    cout << s1.rob(t1);
    return 0;
}
