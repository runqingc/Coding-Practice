#include <iostream>

bool hasAlternatingBits(int n) {
    int last = 2;
    while(n!=0){
        if((n&1)==last){
            return false;
        }
        last = n&1;
        n>>=1;
    }
    return true;
}





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
