#include <iostream>
#include <vector>
using namespace std;

// dp[i][j] the min number of coins to make up amount j using the first i kind of coins
// dp[i][j] = min(dp[i-1][j], dp[i][j-w]+1)
int coinChange(vector<int>& coins, int amount){
    vector<int> dp(amount+1, -1);
    dp[0] = 0;
    for(auto& i: coins){
        for(int j=0; j<=amount; ++j){
            if(j-i>=0 && dp[j-i]>=0){
                if(dp[j]==-1){
                    dp[j] = dp[j-i]+1;
                }else{
                    dp[j] = min(dp[j], dp[j-i]+1);
                }
            }
        }
    }
    return dp[amount];
}


int main() {
    vector<int> coins{1};
    cout << coinChange(coins, 0)<<endl;
    return 0;
}
