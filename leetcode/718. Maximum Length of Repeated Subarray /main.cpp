#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // dp[i][j]: max length of common postfix in first i chars n1, and first j chars in n2

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int max = 0;
        for(int i=0; i<nums1.size(); ++i){
            for(int j=0; j<nums2.size(); ++j){
                if(nums1[i]==nums2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    if(dp[i+1][j+1]>max){
                        max = dp[i+1][j+1];
                    }
                }
            }
        }
        return max;
    }
};



int main() {
    vector<int> nums1{1,2,3,2,1};
    vector<int> nums2{3,2,1,4,7};
    Solution s1;
    cout << s1.findLength(nums1, nums2);

    return 0;
}
