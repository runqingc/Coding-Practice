#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

    // dp[i][j]: number of ways to pack with max volume of j, using the first i kind of coin

    // dp[i][j] = (already done, even if there's no i-th kind of coin) dp[i-1][j]
    //          + dp[i][j-coin]


    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,0));
        dp[0][0] = 1;
        for(int i=1; i<=coins.size(); ++i){
            for(int j=0; j<=amount; ++j){
                dp[i][j] += dp[i-1][j];
                if(j-coins[i-1]>=0){
                    dp[i][j]+=dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};


int main() {
    vector<int> coins{1,2,5};
    int amount = 5;
    Solution s1;
    cout << s1.change(amount, coins);
    return 0;
}
