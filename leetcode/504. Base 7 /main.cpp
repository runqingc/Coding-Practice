#include <iostream>
#include <string>
using namespace std;

string convertToBase7(int num) {
    string flag;
    if(num<0){
        num = -num;
        flag = "-";
    }
    string ans;
    while(num){
        int remainder = num%7;
        num = num/7;
        ans = to_string(remainder)+ans;
    }
    return flag+ans;
}

int main() {
    std::cout << convertToBase7(-100) << std::endl;
    return 0;
}
