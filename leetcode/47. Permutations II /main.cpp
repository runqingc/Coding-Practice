#include <iostream>
#include <vector>
using namespace std;

// n: the actual number chosen
void dfs(vector<vector<int>>& ans, vector<int>& troll, vector<int>& ret, int n, int size){
    troll[n+10]--;
    ret.emplace_back(n);
    if(ret.size()==size){
        ans.emplace_back(ret);
    }else{
        for(int i=0; i<22; ++i){
            if(troll[i]>0){
                dfs(ans, troll, ret, i-10, size);
            }
        }
    }
    troll[n+10]++;
    ret.pop_back();
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int size = (int)nums.size();
    vector<vector<int>> ans;
    vector<int> troll(22, 0);
    for(auto& i: nums){
        ++troll[i+10];
    }
    vector<int> ret;
    for(int i=0; i<22; ++i){
        if(troll[i]>0){
            dfs(ans, troll, ret, i-10, size);
        }
    }

    return ans;
}


int main() {
    vector<int> nums{1,7,2};
    vector<vector<int>> ans = permuteUnique(nums);
    for(auto& i: ans){
        for(auto& j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
