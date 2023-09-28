#include <iostream>
#include <vector>
using namespace std;

// the max profit at the end of the day with 0 stock
// dp[i][0] = max{dp[i-1][0](if do not buy or sell one stock in this day),
//                  dp[i-1][1]+prices[i]-fee(if sell the stock)}
// the max profit at the end of the day with 1 stock
// dp[i][1] = max{dp[i-1][1](if do not buy or sell one stock in this day),
//                  dp[i-1][0]-prices[i]}
int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2));
    dp[0][0] = 0; dp[0][1] = -prices[0];
    for(int i=1; i<prices.size(); ++i){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
    }
    return dp[prices.size()-1][0];
}

int main() {
    vector<int> price{1};
    cout << maxProfit(price, 3) << endl;
    return 0;
}
