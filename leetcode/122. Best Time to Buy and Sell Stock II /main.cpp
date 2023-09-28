#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int cnt = 0;
    for(int i=1; i<prices.size(); i++){
        if(prices[i]>prices[i-1]){
            cnt += prices[i]-prices[i-1];
        }
    }
    return cnt;
}

int main() {
    vector<int> price{7,1,5,3,6,4};
    std::cout << maxProfit(price) << std::endl;
    return 0;
}
