#include <iostream>
#include <vector>
using namespace std;

// dp[i] = max(dp[i-k]*k)
int integerBreak(int n) {
    if(n<=3) return n-1;
    vector<int>dp (60, 1);
    for(int i=1; i<=n; ++i){
        int max = i;
        for(int k=1; k<=i-1; ++k){
            if(dp[i-k]*k>max){
                max = dp[i-k]*k;
            }
        }
        dp[i] = max;
    }
    return dp[n];
}



int main() {
    std::cout << integerBreak(10) << std::endl;

    return 0;
}
