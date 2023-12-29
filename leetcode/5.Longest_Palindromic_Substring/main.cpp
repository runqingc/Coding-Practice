#include <vector>
#include <string>
#include <iostream>
using namespace std;


// dp[i][j] starting from i, length j
// j=0, j=1, true
// j>=2
// if dp[i+1][j-2] and s[i]==s[i+j-1], then true, else false

#define MAXL 1010

class Solution {
    string ans;
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(s.empty()){
            return ans;
        }else{
            ans = s.substr(0,1);
        }
        vector<vector<bool>> dp(len, vector<bool>(len+1, false));
        for(auto& d : dp){
            d[0] = true; d[1] = true;
        }
        for(int j=2; j<=len; ++j){
            for(int i=0; i<len-1; ++i){
                // case when the index exceed the bound
                if(!dp[i+1][j-2] || i+j-1>=len) continue;
                if(s[i]==s[i+j-1]){
                    dp[i][j] = true;
                    if(j>(int)ans.length()){
                        ans = s.substr(i,j);
                    }
                }

            }
        }
        
        return ans;

    }
};


int main(){
    Solution s;
    cout << s.longestPalindrome("bb") << endl;
    return 0;
}