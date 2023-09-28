#include <iostream>
#include <vector>
#include <string>
using namespace std;

// dp[i][j] the edit distance between word1[0~i], word2[0~j]
// dp[i][j] = min{dp[i-1][j]+1, dp[i][j-1]+1, (if word1[i]==word2[j])dp[i-1][j-1]}  ??
int minDistance(string word1, string word2) {
    int m = (int) word1.size();
    int n = (int) word2.size();
    vector<vector<int>> dp (m+1, vector<int>(n+1, 0));
    for(int i=0; i<=m; ++i){dp[i][0] = i;}
    for(int j=0; j<=n; ++j){dp[0][j] = j;}
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
            if(word1[i-1]==word2[j-1]){
                dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
            }
        }
    }
    return dp[m][n];
}


int main() {
    string s1 = "a", s2 = "ab";
    cout << minDistance(s1, s2);
    return 0;
}
