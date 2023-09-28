#include <iostream>
#include <vector>
using namespace std;

vector<bool> used(10, false);
vector<vector<int>> ans;

void dfs(int start, int numCanUse, int sumNeed){

    for(int i=start; i<=9; ++i){
        if(!used[i] && i<sumNeed){
            if(numCanUse-1>0){
                used[i] = true;
                dfs(i+1,numCanUse-1, sumNeed-i);
                used[i] = false;
            }
        }else if(!used[i] && i==sumNeed && numCanUse-1==0){
            used[i] = true;
            vector<int> res;
            for(int j=1; j<=9; ++j){
                if(used[j]) res.push_back(j);
            }
            ans.push_back(res);
            used[i] = false;
        }
    }

}

vector<vector<int>> combinationSum3(int k, int n) {
    dfs(1, k, n);
    return ans;
}


int main() {
    combinationSum3(3,9);
    for(auto& i:ans){
        for(auto& j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
