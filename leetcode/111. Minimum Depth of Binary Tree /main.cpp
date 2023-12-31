#include <iostream>
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
    int min = INT32_MAX;

    void dfs(treeNode* root, int d){
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

    int minDepth(treeNode* root) {
        if(!root) return 0;
        int d = 0;
        dfs(root, d);
        return min;
    }
};


int main() {
    treeNode t9(9);
    treeNode t15(15);
    treeNode t7(7);
    treeNode t20(20, &t15, &t7);
    treeNode t3(3, &t9, &t20);
    Solution S1;
    cout << S1.minDepth(nullptr);
    return 0;
}
