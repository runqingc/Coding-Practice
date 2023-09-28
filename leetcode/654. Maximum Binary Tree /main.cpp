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

TreeNode* build(vector<int>& nums, vector<int>::iterator l, vector<int>::iterator r){
    // find max element
    auto maxIndex = max_element(l, r+1);
    int maxElement = *maxIndex;
    auto root = new TreeNode(maxElement);
    if(maxIndex!=l){
        root->left = build(nums, l, maxIndex-1);
    }
    if(maxIndex!=r){
        root->right = build(nums, maxIndex+1, r);
    }

    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(nums, nums.begin(), nums.end()-1);
}


int main() {
    vector<int> nums{3};
    TreeNode* root = constructMaximumBinaryTree(nums);

    return 0;
}
