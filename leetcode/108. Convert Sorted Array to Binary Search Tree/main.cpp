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


treeNode* build(vector<int>& nums, int l, int r){
    int m = (l+r)/2;
    auto root = new treeNode(nums[m]);
    if(m!=l){
        root->left = build(nums, l, m-1);
    }
    if(m!=r){
        root->right = build(nums, m+1, r);
    }
    return root;
}

treeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, (int)nums.size()-1);
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
