#include <iostream>
#include <string>
using namespace std;

int numDecodings(string s) {
    if(s[0]=='0') return 0;
    int dp_i = 1;
    int dp_i_1 = 1;
    int dp_i_2=1;
    for(int i=1; i<s.length(); ++i){
        if(s[i]=='0'){
            if(s[i-1]!='1' && s[i-1]!='2'){
                return 0;
            }else{
                dp_i = dp_i_2;
            }
        }else{
            if(s[i-1]=='1' || (s[i-1]=='2' && (s[i]-'0'>=0 && s[i]-'0'<=6))){
                dp_i = dp_i_1+dp_i_2;
            }
        }

        dp_i_2 = dp_i_1;
        dp_i_1 = dp_i;
    }
    return dp_i;
}

int main() {
    string s = "1201234";
    std::cout << numDecodings(s) << std::endl;
    return 0;
}
