#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:

    // dp[i][j] = max{dp[i-1][j](discard the i-th element), (if possible, pack the i-th element)dp[i-1][j-w[i]]+v[i] }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = std::accumulate(stones.begin(), stones.end(),0);
        int size = sum/2;
        vector<int> dp1(size+1, 0);
        vector<int> dp2(size+1, 0);
        for(int stone : stones){
            for(int j=0; j<=size; ++j){
                dp2[j]=dp1[j];
                if(j-stone>=0){
                    dp2[j] = max(dp2[j], dp1[j-stone]+stone);
                }
            }
            dp2.swap(dp1);
        }
        return sum-2*dp1.back();
    }
};



int main() {
    Solution s1;
    vector<int> nums{31,26,33,21,40};
    cout << s1.lastStoneWeightII(nums);
    return 0;
}
