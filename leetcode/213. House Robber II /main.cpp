#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// dp[i] = max(dp[i-1](if do not rob this house), dp[i-2]+v[i](if rob this house))
int robHouse(vector<int>& nums, int l, int r){
    int dp0=0, dp1=0, dp2=0;
    for(int i=l; i<=r; ++i){
        dp0 = max(dp1, dp2+nums[i]);
        dp2 = dp1;
        dp1 = dp0;
    }
    return dp1;
}


int rob(vector<int>& nums) {
    if (nums.size() <= 3)
        return *(max_element(nums.begin(), nums.end()));
    return max({robHouse(nums, 1, (int)nums.size()-3)+nums.back(),
                robHouse(nums, 2, (int)nums.size()-2)+nums.front(),
                robHouse(nums, 1, (int)nums.size()-2)});
}


int main() {
    vector<int> nums {1,2,3,4,5,6,7,8,9};
    cout << rob(nums) << endl;
    return 0;
}
