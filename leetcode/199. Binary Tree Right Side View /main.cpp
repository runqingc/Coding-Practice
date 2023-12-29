#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> rightSideView(TreeNode* root) {

    vector<int> ans;
    int cur_height = 0;
    deque<pair<TreeNode*, int>> q;
    q.emplace_front(root, 0);
    while(!q.empty()){
        if(q.front().second==cur_height){
            if(!ans.empty())ans.pop_back();
            ans.emplace_back(q.front().first->val);
        }else if(q.front().second>cur_height){
            ans.push_back(q.front().first->val);
            cur_height = q.front().second;
        }
        if(q.front().first->left)q.emplace_back(q.front().first->left, q.front().second+1);
        if(q.front().first->right)q.emplace_back(q.front().first->right, q.front().second+1);
        q.pop_front();
    }

    return ans;

}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
