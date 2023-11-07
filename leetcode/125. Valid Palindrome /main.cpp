#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string s) {
    auto i = s.begin(), j = s.end()-1;
    while(i<j){
        if(*i>='a' && *i<='z'){
            *i -= ('a'-'A');
        }
        if(!(*i>='A' && *i<='Z' || *i>='0' && *i<='9')){
            ++i;
            continue;
        }
        if(*j>='a' && *j<='z'){
            *j -= ('a'-'A');
        }
        if(!(*j>='A' && *j<='Z' || *j>='0' && *j<='9')){
            --j;
            continue;
        }
        if(*i!=*j){
            return false;
        }else{
            ++i, --j;
        }
    }
    return true;
}

int main() {
    std::cout << isPalindrome("0P") << std::endl;
    return 0;
}
