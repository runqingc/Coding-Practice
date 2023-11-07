#include <iostream>
#include <algorithm>
using namespace std;

long long minIncrementOperations(vector<int>& nums, int k) {


    vector<long long>dp(4, 0);
    vector<int>nums3 = nums;
    vector<int>nums2 = nums;
    vector<int>nums1 = nums;
    vector<int>nums0 = nums;

    dp[3] = max(0, k-*max_element(nums3.begin(), nums3.begin()+3));
    if(*max_element(nums.begin(), nums.begin()+3)<k){

    }
    dp[2] = dp[3];
    dp[1] = max(0, k-*max_element(nums.begin(), nums.begin()+2));
    dp[0] = max(0, k-*max_element(nums.begin(), nums.begin()+1));

    for(auto i = nums.begin()+1; (i+2)!=nums.end(); ++i){

        dp[3] += max(0, k-*(i+2));
        if(i-1>=nums.begin()){
            dp[3] = min(dp[3],  dp[1]+ max(0, k-*max_element(i+1, i+3)));
        }
        if(i-2>=nums.begin()){
            dp[3] = min(dp[3], dp[0]+max(0, k-*max_element(i, i+3)));
        }

        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[3];

    }

    return dp[3];
}

int main() {
    vector<int> nums{0,1,3,3};
    cout << minIncrementOperations(nums, 5);
    return 0;
}
