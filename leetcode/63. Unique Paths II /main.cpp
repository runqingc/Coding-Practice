#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // dp[i][j] = dp[i-1][j] + dp[i][j-1]
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int) obstacleGrid.size();
        int n = (int) obstacleGrid[0].size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        dp1[0] = 1;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(obstacleGrid[i][j]){
                    dp1[j]=0;
                }else{
                    dp1[j] += dp2[j];
                    if(j-1>=0){
                        dp1[j] += dp1[j-1];
                    }
                }
            }
            dp1.swap(dp2);
            fill(dp1.begin(), dp1.end(), 0);
        }
        return dp2[n-1];
    }
};



int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution s1;
    cout << s1.uniquePathsWithObstacles(obstacleGrid);
    return 0;
}
