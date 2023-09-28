#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // pair[0] do not rob; pair[1] rob
    void post(unordered_map<TreeNode*, pair<int, int>>& umap, TreeNode* root){
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


    int rob(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> umap;
        post(umap, root);
        return max(umap[root].first, umap[root].second);
    }
};



int main() {

    auto t1 = new TreeNode(4);
    auto t2 = new TreeNode(1);
    auto t3 = new TreeNode(2);
    auto t4 = new TreeNode(3);
    auto t5 = new TreeNode(3);
    auto t6 = new TreeNode(1);
    t1->left = t2;
//    t1->right = t3;
    t2->left = t3;
    t3->left = t4;
//    t3->right =t6;
    Solution s1;
    cout << s1.rob(t1);
    return 0;
}
