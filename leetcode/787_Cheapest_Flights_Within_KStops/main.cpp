#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define INF 1000020

// dp[i][j] min cost to reach city j within i edge
// for every edge start->end with cost: 
// dp[i][end] = min(dp[i][end], dp[i-1][start]+cost)

class Solution {

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ++k;
        vector<vector<int>> dp(k+1, vector<int>(n, INF));
        dp[0][src] = 0;
        for(int i=1; i<=k; ++i){
            for(auto &edge: flights){
                dp[i][edge[1]] = min(dp[i][edge[1]], dp[i-1][edge[0]]+edge[2]);
            }
        }
        // shortest might be 1 step, 2 step, 3 step ...
        int ans = INF; 
        for(auto &step: dp) 
            ans = min(step[dst], ans);
        return (ans==INF)?(-1):(ans);
    }
};



int main(){

    int n = 4;
    vector<vector<int>> flights {{0,1,1}, {1,2,1}, {2,0,1},{1,3,6}, {2,3,2}};
    Solution s;
    cout << s.findCheapestPrice(n, flights, 0, 3, 1);

    return 0;
}