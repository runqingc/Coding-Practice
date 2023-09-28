#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int size = (int) nums.size();
    vector<vector<int>> ans;
    if(size<=2) return ans;
    sort(nums.begin(), nums.end());
    int l, m, r;
    int pl, pr;
    for(m=0; m<nums.size()-2; ++m){
        if(nums[m]>0) break;
        if(m>=1 && nums[m]==nums[m-1]){
            continue;
        }
        l=m+1, r = (int)nums.size()-1;
        while(l<r){
            if(nums[m]+nums[l]+nums[r]==0){
                ans.emplace_back(vector<int>{nums[m], nums[l], nums[r]});
                // move l right and r left
                pl = nums[l];
                ++l;
                while(l<r && (nums[l]==pl || l==m)){
                    ++l;
                }
                pr = nums[r];
                --r;
                while(l<r && (nums[r]==pr || r==m)){
                    --r;
                }
            }else if(nums[m]+nums[l]+nums[r]<0){
                pl = nums[l];
                ++l;
                while(l<r && (nums[l]==pl || l==m)){
                    ++l;
                }
            }else{
                pr = nums[r];
                --r;
                while(l<r && (nums[r]==pr || r==m)){
                    --r;
                }
            }

        }

    }

    return ans;
}


int main() {
    vector<int> nums{0,0,0,0};
    vector<vector<int>> ans = threeSum(nums);
    for(auto& i: ans){
        for(auto& j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
