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

treeNode* build(vector<int>& nums, vector<int>::iterator l, vector<int>::iterator r){
    // find max element
    auto maxIndex = max_element(l, r+1);
    int maxElement = *maxIndex;
    auto root = new treeNode(maxElement);
    if(maxIndex!=l){
        root->left = build(nums, l, maxIndex-1);
    }
    if(maxIndex!=r){
        root->right = build(nums, maxIndex+1, r);
    }

    return root;
}

treeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(nums, nums.begin(), nums.end()-1);
}


int main() {
    vector<int> nums{3};
    treeNode* root = constructMaximumBinaryTree(nums);

    return 0;
}
