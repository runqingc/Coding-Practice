#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int countPrimes(int n) {
    if(n<=1){
        return 0;
    }
    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    // 从1 到n 遍历，假设当前遍历到m，则把所有小于n 的、且是m 的倍
    //数的整数标为和数；遍历完成后，没有被标为和数的数字即为质数。
    for(int i=2; i<=ceil(sqrt(n)); ++i){
        for(int j=2; i*j<n; ++j){
            isPrime[i*j] = false;
        }
    }
    int cnt = 0;
    for(auto i: isPrime){
        if(i){
            ++cnt;
        }
    }
    return cnt;
}


int main() {

    cout << countPrimes(10);

    return 0;
}
