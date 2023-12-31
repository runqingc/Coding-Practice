#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;


struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    treeNode* origin;
    int cnt;

    // 0 not covered, waiting to be covered by parent node
    // 1 covered
    // 2 has a camera on it
    int post(treeNode* root){
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


    int minCameraCover(treeNode* root) {
        if(!root->left && !root->right) return 1;
        cnt = 0;
        origin = root;
        post(root);
        return cnt;
    }
};


int main() {
    Solution s1;
    auto t1 = new treeNode(1);
    auto t2 = new treeNode(2);
    auto t3 = new treeNode(3);
    auto t4 = new treeNode(4);
    auto t5 = new treeNode(5);
    auto t6 = new treeNode(6);
    t1->left = t2;
    t2->left = t3;
    t2->right = t4;
    cout << s1.minCameraCover(t1);

    return 0;
}
