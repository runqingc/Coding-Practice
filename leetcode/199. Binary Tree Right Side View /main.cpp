#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};


vector<int> rightSideView(treeNode* root) {

    vector<int> ans;
    int cur_height = 0;
    deque<pair<treeNode*, int>> q;
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
