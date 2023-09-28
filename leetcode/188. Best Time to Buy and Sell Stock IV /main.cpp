#include <iostream>
#include <vector>
using namespace std;

// max profit at the end of day i with 1 stock, accomplished j transactions
// buy[i][j] = max(buy[i-1][j](if do not buy on day i), sell[i-1][j-1]-prices[i](if buys on day i))
// max profit at the end of day i with 0 stock, accomplished j transactions
// sell[i][j] = max(sell[i-1][j](if do not sell on day i), buy[i-1][j-1]+prices[i](if sells on day j))

int maxProfit(int k, vector<int>& prices) {
    vector<vector<int>> buy(prices.size(), vector<int>(k+1, 0));
    vector<vector<int>> sell(prices.size(), vector<int>(k+1, 0));
    for(auto& j: buy[0]) j = -prices[0];
    for(int i=1; i<prices.size(); ++i){
        for(int j=1; j<=k; ++j){
            buy[i][j] = max(buy[i-1][j], sell[i-1][j-1]-prices[i]);
            sell[i][j] = max(sell[i-1][j], buy[i-1][j]+prices[i]);
        }
    }
    return sell[prices.size()-1][k];
}

int main() {
    vector<int> prices{3,2,6,5,0,3,0,10,0,10};
    int k = 3;
    cout << maxProfit(k, prices);
    return 0;
}
