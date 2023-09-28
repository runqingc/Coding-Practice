#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& ret, vector<bool>& chosen, int start, int n, int k){
    for(int i=start; i<=n; ++i){
        ret.emplace_back(i);
        chosen[i] = true;
        if(ret.size()<k){
            dfs(ans, ret, chosen, i+1, n, k);
        }else if(ret.size()==k){
            ans.emplace_back(ret);
        }
        ret.pop_back();
        chosen[i] = false;
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> ret;
    vector<bool> chosen(n+1, false);
    dfs(ans, ret, chosen, 1, n, k);
    return ans;
}


int main() {
    vector<vector<int>> ans = combine(7, 3);
    for(auto& i: ans){
        for(auto& j: i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
