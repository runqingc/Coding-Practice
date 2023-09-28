#include <iostream>
#include <vector>
using namespace std;

#define MAXN 52

void dfs(vector<vector<int>>& ans, vector<int>& ret, vector<int>& troll, int target, int n, int size){
    --troll[n];
    ret.emplace_back(n);
    target -= n;
    if(target==0){
        ans.emplace_back(ret);
    }else{
        for(int i=n; i<=target; ++i){
            if(troll[i]!=0){
                dfs(ans, ret, troll, target, i, size);
            }
        }
    }
    ++troll[n];
    ret.pop_back();
    target += n;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ret;
    int size = (int) candidates.size();
    vector<int> troll(MAXN, 0);
    for(auto& i: candidates){
        ++troll[i];
    }
    for(int i=0; i<=target; ++i){
        if(troll[i]!=0){
            dfs(ans, ret, troll, target, i, size);
        }
    }

    return ans;
}


int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int>> ans = combinationSum2(candidates, 8);
    for(auto& i: ans){
        for(auto& j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
