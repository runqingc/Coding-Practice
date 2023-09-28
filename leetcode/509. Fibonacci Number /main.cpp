#include <iostream>
using namespace std;
class Solution {
public:
    // dp[i] = dp[i-1]+dp[i-2]
    int fib(int n) {

        int a = 1;
        int b = 1;
        if(n==0) return 0;
        if(n<=2) return 1;
        int c;
        for(int i=2; i<n; ++i){
            c = a+b;
            a = b;
            b = c;
        }
        return b;
    }
};




int main() {

    Solution s1;
    cout << s1.fib(4)<< endl;

    return 0;
}
