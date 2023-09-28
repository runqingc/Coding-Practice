#include <iostream>
#include <vector>
using namespace std;

// buy[i] the max profit with 1 stock at the end of i-th day
//  = max{buy[i-1], cool[i-1]-price[i]}
// sell[i] the max profit with 0 stock at the end of i-th day
//  = max{sell[i-1], buy[i-1]+price[i]}
// cool[i] the max profit at the end of day i (the i-th day do nothing)
//  = sell[i-1]
int maxProfit(vector<int>& prices) {
    int buy0 = -prices[0], sell0 = 0, cool0 = 0;
    int buy1, sell1, cool1;
    for(int i=1; i<prices.size(); ++i){
        buy1 = max(buy0, cool0-prices[i]);
        sell1 = max(sell0, buy0+prices[i]);
        cool1 = sell0;
        buy0 = buy1;
        sell0 = sell1;
        cool0 = cool1;
    }
    return sell0;
}


int main() {
    vector<int>prices {1};
    cout << maxProfit(prices);
    return 0;
}
