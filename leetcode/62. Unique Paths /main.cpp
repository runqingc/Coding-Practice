#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
#define ll long long


    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i-1>=0){
                    dp[i][j]+=dp[i-1][j];
                }
                if(j-1>=0){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];

    }
};




int main() {
    Solution s1;
    cout << s1.uniquePaths(100, 3);
    return 0;
}
