#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.size()<=3) return ans;
    sort(nums.begin(), nums.end());
    vector<long> n(nums.size());
    for(int i=0; i<nums.size(); ++i){
        n[i] = nums[i];
    } 
    for(int i=0; i<n.size()-3; ++i){
        if(i>0 && n[i]==n[i-1]) continue;
        for(int j=i+1; j<n.size()-2; ++j){
            if(j>i+1 && n[j]==n[j-1]) continue;
            int l = j+1, r = (int)n.size()-1;
            while(l<r){
                long pl = n[l], pr = n[r];
                long long curSum = n[i]+n[j]+n[l]+n[r];
                if(curSum==target){
                    ans.emplace_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                    do{++l;}while(l<r && n[l]==pl);
                    do{--r;}while(l<r && n[r]==pr);
                }else if(curSum<target){
                    do{++l;}while(l<r && n[l]==pl);
                }else{
                    do{--r;}while(l<r && n[r]==pr);
                }
            }
        }
    }
    return ans;
}



int main() {
    vector<int> nums{1,-2,-5,-4,-3,3,3,5};
    vector<vector<int>> ans = fourSum(nums, -11);
    for(auto& i: ans){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
