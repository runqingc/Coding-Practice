#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// dp[i] the number of ways you can buy utils for sum i
// dp[i] = dp[i-cost1]+dp[i-cost2]
#define ll long long
long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    ll sum = 0;
    if(cost1>cost2){
        int tmp = cost1; cost1 = cost2; cost2 = tmp;
    }
    for(int i=0; i<=total/cost2; ++i){
        sum += (total-i*cost2)/cost1+1;
    }
    return sum;
}


int main() {
    cout << waysToBuyPensPencils(1000000,1,1)<< endl;
    return 0;
}
