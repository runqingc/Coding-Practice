#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int* dp = new int[m];
        int i, j;
        for(j=0; i<n; i++){
            for(i=0; i<m; j++){
                if(i==0 && j==0){
                    dp[i] = grid[i][j];
                }else if(j==0){
                    dp[i] = dp[i-1] + grid[i][j];
                }else if(i==0){
                    dp[i] = dp[0] + grid[i][j];
                }else{
                    dp[i] = min(dp[i-1], dp[i]) + grid[i][j];
                }
            }
        }
        
        return dp[m-1];

    }
};