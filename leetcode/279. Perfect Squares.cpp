#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        if(n==1) return 1;
        int* dp = new int[n+2];
        dp[1] = 1;
        int i, j, key=1, next_squre = 4;
        int this_dp = 0;
        for(i=2; i<=n; i++){
            if(i==next_squre){
                dp[i] = 1;
                key++;
                next_squre = (key+1)*(key+1);
            }else{
                this_dp = INT_MAX-1;
                for(j=1; j<=key; j++){
                    int pre = i-j*j;
                    if(dp[pre]<this_dp){
                        this_dp = dp[pre];
                    }
                }
                dp[i] = this_dp+1;
            }

        }
        return dp[n];

    }
};


class Solution {
public:
    int numSquares(int n) {
        if(n==1) return 1;
        int* dp = new int[n+2];
        dp[1] = 1;
        int i, j, key=1, next_squre = 4;
        int this_dp = 0;
        for(i=2; i<=n; i++){
            if(i==next_squre){
                dp[i] = 1;
                key++;
                next_squre = (key+1)*(key+1);
            }else{
                this_dp = INT_MAX-1;
                for(j=1; j<=key; j++){
                    int pre = i-j*j;
                    if(dp[pre]<this_dp){
                        this_dp = dp[pre];
                    }
                }
                dp[i] = this_dp+1;
            }

        }
        return dp[n];

    }
};