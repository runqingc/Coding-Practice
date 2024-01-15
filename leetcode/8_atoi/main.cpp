#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        
        long ans = 0;

        int i;
        int sign=1;
        // skip white space
        for(i=0; i<s.size(); ++i){
            if(s[i]!=' '){
                break;
            }
        }
        // check first non-blank charactor
        if(s[i]=='-'){
            sign = -1;
            ++i;
        }else if(s[i]=='+'){
            sign = 1;
            ++i;
        }else if(s[i]<'0' || s[i]>'9'){
            return 0;
        }
        // read in numbers
        string numberString = "";
        for(; i<s.size(); ++i){
            if(s[i]>='0' && s[i]<='9'){
                numberString += s[i];
            }else{
                break;
            }
        }
        // address min/max value
        for(i=0; i<static_cast<int>(numberString.size()); ++i){
            ans *= 10;
            ans += numberString[i]-'0';
            if(ans*sign>=INT32_MAX){
                return INT32_MAX;
            }else if(ans*sign<=INT32_MIN){
                return INT32_MIN;
            }
        }

        return static_cast<int>(ans)*sign;
    }
};


int main(){
    Solution s;
    cout << s.myAtoi("4");

    return 0;
}