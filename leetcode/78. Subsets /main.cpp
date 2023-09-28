#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(vector<int>::iterator l, vector<int>::iterator r){

        for(auto i = l; i<r; ++i){
            if(i!=l && *i==*(i-1)) continue;
            cur.push_back(*i);
            ans.push_back(cur);
            if(i+1<r){
                dfs(i+1, r);
            }
            cur.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        ans.push_back(cur);
        dfs(nums.begin(), nums.end());
        return ans;
    }
};



int main() {
    Solution s1;
    vector<int> nums{1,2,2};
    auto ans = s1.subsets(nums);

    for(auto& i: ans){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
