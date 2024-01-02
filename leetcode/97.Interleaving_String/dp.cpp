#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // dp[i][j]:
    // can first i-th and first j-th chars construct s3? 
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        dp[0][0] = true;
        for(int i=0; i<=s1.size(); ++i){
            for(int j=0; j<=s2.size(); ++j){
                if((i>0 && dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (j>0 && dp[i][j-1] && s2[j-1]==s3[i+j-1])){
                    dp[i][j]=true;
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main(){

    Solution s;
    cout << boolalpha;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc");



    return 0;
}
