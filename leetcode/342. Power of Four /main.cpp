#include <iostream>
using namespace std;
bool isPowerOfFour(int n) {

    while(n>4){
        if((n&1)!=0 || (n&2)!=0){
            return false;
        }
        n >>= 2;
    }
    return n==4 || n==1;
}

int main() {
    int n=16;

//    cout << (16&1);
    std::cout << isPowerOfFour(5) << std::endl;
    return 0;
}
