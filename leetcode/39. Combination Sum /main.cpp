#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(vector<int>& candidates, int need, int start){

        for(int i=start; i<candidates.size(); ++i){
            if(candidates[i]<need){
                cur.push_back(candidates[i]);
                dfs(candidates, need-candidates[i], i);
                cur.pop_back();
            }
            else if(candidates[i]==need){
                cur.push_back(candidates[i]);
                ans.push_back(cur);
                cur.pop_back();
            }else break;
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target,0);
        return ans;
    }
};





int main() {
    vector<int> candidates{2,3,5};
    int target = 8;
    Solution s1;
    s1.ans = s1.combinationSum(candidates, target);
    for(auto& i: s1.ans){
        for(auto& j: i){
            cout << j;
        }
        cout << endl;
    }

    return 0;
}
