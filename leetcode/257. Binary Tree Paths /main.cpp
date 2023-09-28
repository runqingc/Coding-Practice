#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };


void dfs(TreeNode* root, string ans, vector<string>& ret){
    ans += "->" ;
    ans += to_string(root->val);
    if(root->left){
        dfs(root->left, ans, ret);
    }
    if(root->right){
        dfs(root->right, ans, ret);
    }
    if(!root->left && !root->right){
        ret.emplace_back(ans);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    string ans = to_string(root->val);
    vector<string> ret;
    if(root->left){
        dfs(root->left, ans, ret);
    }
    if(root->right){
        dfs(root->right, ans, ret);
    }
    return ret;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
