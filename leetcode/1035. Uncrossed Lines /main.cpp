#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // dp[i][j]: the max lines we can draw within:
    // the first i elements in nums1
    // and first j elements in nums2
    // dp[i][j] = max{dp[i-1][j], dp[i][j-1], (if nums1[i]==nums2[j])dp[i-1][j-1]+1}

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for(int i=0; i<nums1.size(); ++i){
            for(int j=0; j<nums2.size(); ++j){
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                if(nums1[i]==nums2[j] && dp[i][j]+1>dp[i+1][j+1]){
                    dp[i+1][j+1] = dp[i][j]+1;
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};


int main() {

    vector<int>nums1{2,5,1,2,5};
    vector<int>nums2{10,5,2,1,5,2};
    Solution s1;
    cout << s1.maxUncrossedLines(nums1, nums2);


    return 0;
}
