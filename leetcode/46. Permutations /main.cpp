#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& ret, vector<int>& nums, vector<bool>& visited){
    for(int i=0; i<nums.size(); ++i){
        if(!visited[i]){
            visited[i] = true;
            ret.emplace_back(nums[i]);
            if(ret.size()<visited.size()){
                dfs(ans, ret, nums, visited);
            }else{
                ans.emplace_back(ret);
            }
            visited[i] = false;
            ret.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ret;
    vector<bool> visited(nums.size(), false);
    dfs(ans, ret, nums, visited);
    return ans;
}

int main() {
    vector<int> nums {1,1,2};
    vector<vector<int>> ans = permute(nums);
    for(auto& i: ans){
        for(auto& j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
