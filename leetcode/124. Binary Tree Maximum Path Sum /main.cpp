#include <iostream>
#include <algorithm>
using namespace std;

struct treeNode {
        int val;
        treeNode *left;
        treeNode *right;
        treeNode() : val(0), left(nullptr), right(nullptr) {}
        treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:

    int max_route = INT32_MIN;

    int pathSum(treeNode* root) {

        int left_maxsum=0, right_max_sum=0;
        if(root->left) left_maxsum = pathSum(root->left);
        if(root->right) right_max_sum = pathSum(root->right);
        int this_max = root->val;
        if(left_maxsum>0) this_max+= left_maxsum;
        if(right_max_sum>0) this_max+= right_max_sum;

        max_route = max(max_route, this_max);
        if(max(left_maxsum, right_max_sum)>0){
            return max(left_maxsum, right_max_sum)+root->val;
        }
        return root->val;
    }

    int maxPathSum(treeNode* root) {
        max_route = root->val;
        pathSum(root);
        return max_route;
    }
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
