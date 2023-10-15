#include <iostream>

int trailingZeroes(int n) {
    long divisor = 5;
    long quotient = n/divisor;

    long ans = 0;
    while(quotient){
        ans+=quotient;
        divisor*=5;
        quotient = n/divisor;
    }

    return (int)ans;
}



int main() {
    std::cout << trailingZeroes(5) << std::endl;
    return 0;
}
