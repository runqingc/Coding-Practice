#include <iostream>
#include <string>
using namespace std;

// dp[i][j] the longest common sequence within:
// i th character in text1
// j th character in text2
// dp[i][j] = max{dp[i-1][j], dp[i][j-1], (if possible)dp[i-1][j-1]+1}
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
    for(int i=0; i<text1.size(); ++i){
        for(int j=0; j<text2.size(); ++j){
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            if(text1[i]==text2[j]){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}


int main() {
    string s1 = "adorable";
    string s2 = "rainbow";
    cout << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}
