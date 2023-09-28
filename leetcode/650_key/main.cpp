#include <iostream>
#include <vector>
using namespace std;


// dp[i][j] the min steps need to get string i, with a copy of j 'A's at hand
// dp[i][j] = (if i-j>=j)dp[i-j][j]+1, if(i==j) min(dp[i])+1 (copy itself)
// ans = dp[i][i]-1, j in (1, i-1]
#define INFINITY 1020
int minSteps(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    dp[1][1] = 1;
    for(int i=2; i<=n; ++i){
        int min = INFINITY;
        for(int j=1; j<=i; ++j){
            if(i-j>=j){
                dp[i][j] = dp[i-j][j]+1;
                if(dp[i][j]<min) min = dp[i][j];
            } else if(i==j){
                dp[i][j] = min+1;
            }else{
                dp[i][j] = INFINITY;
            }
        }
    }
    return dp[n][n]-1;
}

int main() {
    cout << minSteps(9);
    return 0;
}
