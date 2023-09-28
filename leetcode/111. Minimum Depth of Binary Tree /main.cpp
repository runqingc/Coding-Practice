#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    int min = INT32_MAX;

    void dfs(TreeNode* root, int d){
        if(!root) return;
        if (d + 1 > min) return;
        // root not empty, current depth: d+1
        if(!root->left && !root->right){
            if(d+1<min) min = d+1;
        }
        if(root->left){
            dfs(root->left, d+1);
        }
        if(root->right){
            dfs(root->right, d+1);
        }
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int d = 0;
        dfs(root, d);
        return min;
    }
};


int main() {
    TreeNode t9(9);
    TreeNode t15(15);
    TreeNode t7(7);
    TreeNode t20(20, &t15, &t7);
    TreeNode t3(3, &t9, &t20);
    Solution S1;
    cout << S1.minDepth(nullptr);
    return 0;
}
