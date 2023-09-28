#include<vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max_area = 0;
        vector<vector<int>> dp (m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='0'){
                    dp[i][j] = 0;
                }else if(i==0 || j==0 || matrix[i-1][j]=='0' || matrix[i][j-1] == '0' || matrix[i-1][j-1]=='0'){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 1+ min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
                if(dp[i][j]>max_area){
                    max_area = dp[i][j];
                }
            }
        }
        return max_area*max_area;
    }
};
