#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:

    vector<vector<int>>ans;
    vector<int> cur;

    void dfs(vector<int>::iterator l, vector<int>::iterator r){
        set<int> used;
        for(auto i=l; i<r; ++i){
            if(i!=l && *i==*(i-1)) continue;
            if(used.find(*i)==used.end()){
                used.insert(*i);
                if(cur.empty() || *i>=cur.back()){
                    cur.push_back(*i);
                    if(cur.size()>=2) ans.push_back(cur);
                    dfs(i+1, r);
                    cur.pop_back();
                }
            }

        }

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums.begin(), nums.end());
        return ans;
    }
};


int main() {
    Solution s1;
    vector<int> nums{1,2,3,1,2,3};
    auto ret = s1.findSubsequences(nums);
    for(auto& i: ret){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
