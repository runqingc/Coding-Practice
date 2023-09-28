#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // dp[i] = min{dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]}
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()<=1) return 0;
        int dpi, dpi1=0, dpi2=0;
        for(int i=2; i<=cost.size(); ++i){
            dpi = min(dpi1+cost[i-1], dpi2+cost[i-2]);
            dpi2 = dpi1;
            dpi1 = dpi;
        }
        return dpi1;
    }
};



int main() {
    vector<int> cost{10,100};
    Solution s1;
    std::cout << s1.minCostClimbingStairs(cost)<< std::endl;
    return 0;
}
