#include<vector>
#include<limits.h>
using namespace std;


class Solution {
public:

    int m;
    int n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> dp (m, vector<int> (n, INT_MAX-1));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    dp[i][j] = 0;
                }else{
                    if(j==0 && i!=0){
                        if(dp[i-1][j]<INT_MAX-1) dp[i][j] = dp[i-1][j]+1;
                    }else if(i==0 && j!=0){
                        if(dp[i][j-1]<INT_MAX-1) dp[i][j] = dp[i][j-1]+1;
                    }else if(i && j){
                        if(min(dp[i][j-1], dp[i-1][j])<INT_MAX-1) dp[i][j] = min(dp[i][j-1], dp[i-1][j])+1;
                    }
                }
            }
        }

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                
                if(i==m-1 && j!=n-1){
                    dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
                }else if(i!=m-1 && j==n-1){
                    dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                }else if(i!=m-1 && j!=n-1){
                    dp[i][j] = min(dp[i][j], min(dp[i][j+1]+1, dp[i+1][j]+1));
                }
                
            }
        }

        return dp;
    }
};
