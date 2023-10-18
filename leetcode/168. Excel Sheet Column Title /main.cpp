#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int columnNumber) {
    string ans;

    while(columnNumber>0){
        --columnNumber;
        char c=(char)('A'+columnNumber%26);
        ans = c + ans;

        columnNumber /= 26;
    }
    return ans;
}


int main() {
    std::cout << convertToTitle(26) << std::endl;
    return 0;
}
