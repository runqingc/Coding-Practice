#include <iostream>



int findComplement(int num) {
    int ans = 0;
    for(int i=0; num!=0; ++i){
        ans |= ((~num&1)<<i);
        num>>=1;
    }
    return ans;
}



int main() {
    std::cout << findComplement(5) << std::endl;
    return 0;
}
