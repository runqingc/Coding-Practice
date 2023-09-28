#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// dp[i][j] = max{dp[i-1][j], dp[i-1][j-w]+v}
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%2!=0) return false;
    int half = sum/2;
    vector<int> dp1(half+1, 0);
    vector<int> dp2(half+1, 0);
    for(auto& i: nums){
        for(int j=0; j<=half; ++j){
            dp2[j] = dp1[j];
            if(j-i>=0){
                dp2[j] = max(dp2[j], dp1[j-i]+i);
            }
        }
        dp1.swap(dp2);
    }
    return dp1[half]==half;
}


int main() {
    vector<int> nums{2,4,6,10};
    cout << canPartition(nums) << endl;
    return 0;
}
