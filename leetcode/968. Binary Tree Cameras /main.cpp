#include <iostream>
#include <list>
#include <vector>
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

    TreeNode* origin;
    int cnt;

    // 0 not covered, waiting to be covered by parent node
    // 1 covered
    // 2 has a camera on it
    int post(TreeNode* root){
        if(root){
            if(!root->left && !root->right){
                return 0;
            }
            int l = post(root->left);
            int r = post(root->right);
            if(l==0 || r==0){
                ++cnt;
                return 2;
            }
            if(l+r>=3){
                return 1;
            }
            // l=r=1:
            if(root==origin){
                ++cnt;
                return 2;
            }else{
                return 0;
            }
        }
        return 1;
    }


    int minCameraCover(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        cnt = 0;
        origin = root;
        post(root);
        return cnt;
    }
};


int main() {
    Solution s1;
    auto t1 = new TreeNode(1);
    auto t2 = new TreeNode(2);
    auto t3 = new TreeNode(3);
    auto t4 = new TreeNode(4);
    auto t5 = new TreeNode(5);
    auto t6 = new TreeNode(6);
    t1->left = t2;
    t2->left = t3;
    t2->right = t4;
    cout << s1.minCameraCover(t1);

    return 0;
}
