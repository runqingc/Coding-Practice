#include <iostream>

int hammingDistance(int x, int y) {
    int var = (x^y);
    int cnt = 0;
    while(var){
        cnt+=(var & 1);
        var>>=1;
    }
    return cnt;
}



int main() {
    std::cout << hammingDistance(5,9) << std::endl;
    return 0;
}
