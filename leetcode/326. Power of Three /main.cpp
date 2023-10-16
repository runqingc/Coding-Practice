#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfThree(int n) {
    return n>0 && 1162261467%n==0;
}


int main() {
    long powerOfThree=1;
    while(powerOfThree*3<INT32_MAX){
        powerOfThree*=3;
    }
    cout << powerOfThree;

    return 0;
}
