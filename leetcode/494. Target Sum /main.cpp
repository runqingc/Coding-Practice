#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// dp[i][j] = k
// there are k ways to make sum j using the first i numbers
// dp[i][j] = dp[i-1][j] (if the i-th number is not chosen)
//           + dp[i-1][j-nums[i]] (if the i-th number is chosen)
int findTargetSumWays(vector<int>& nums, int target) {
    if(target<0) return 0;
    int numZero = 0;
    vector<int>n;
    for(auto& i: nums){
        if(i==0){
            ++numZero;
        }else{
            n.push_back(i);
        }
    }
    n.swap(nums);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if((sum+target)%2!=0) return 0;
    sum = (sum+target)/2;
    vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, 0));
    for(int i=0; i<=nums.size(); ++i) dp[i][0] = 1;
    for(int i=1; i<=nums.size(); ++i){
        for(int j=sum; j>0; --j){
            dp[i][j] = dp[i-1][j];
            if(j-nums[i-1]>=0){
                dp[i][j]+=dp[i-1][j-nums[i-1]];
            }
        }
    }
    return dp[nums.size()][sum]*(int)pow(2, numZero);
}


int main() {
    vector<int> nums {0,0,0,0,0,0,0,0,1};
    int target = 1;
    cout << findTargetSumWays(nums, target);
    return 0;
}
