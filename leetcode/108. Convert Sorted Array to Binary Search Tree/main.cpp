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


TreeNode* build(vector<int>& nums, int l, int r){
    int m = (l+r)/2;
    auto root = new TreeNode(nums[m]);
    if(m!=l){
        root->left = build(nums, l, m-1);
    }
    if(m!=r){
        root->right = build(nums, m+1, r);
    }
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, (int)nums.size()-1);
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
