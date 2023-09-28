#include <iostream>
#include <string>
using namespace std;
class Solution {
public:

    // dp[i][j]: number of ways to get t from s, within s[0~i-1], t[0~j-1]
    // dp[i][j] = dp[i-1][j](if s[i-1] not used) + (if s[i-1]==t[j-1] can be used) dp[i-1][j-1]
    //
    int numDistinct(string s, string t) {
        vector<vector<unsigned>> dp(s.size()+1, vector<unsigned>(t.size()+1, 0));
        for (int i = 0; i <= s.size(); ++i) {
            dp[i][0] = 1;
        }
        for(int i=1; i<=s.size(); ++i){
            for(int j=1; j<=t.size(); ++j){
                dp[i][j] = dp[i-1][j];
                if(s[i-1]==t[j-1]){
                    dp[i][j]+=dp[i-1][j-1];
                }
            }
        }
        return dp[s.size()][t.size()];
    }


};
int main() {

    Solution s1;
    string s="adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaa"
             "eeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc", t="bcddceeeebecbc";

    cout << s1.numDistinct(s, t);

    return 0;
}
